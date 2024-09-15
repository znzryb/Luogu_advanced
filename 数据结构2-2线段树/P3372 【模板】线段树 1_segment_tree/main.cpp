#include <iostream>
using namespace std;
int n,m,op,x,y;
const int maxn=1e6+10,maxn4=4*maxn;
long long int a[maxn],sumA[maxn],k,lazy[maxn4],result;
struct rangeSES {
    long long int s;long long int e;long long int sumR;
}tree[maxn4];
void buildTree(int fa) {
    if(tree[fa].s==tree[fa].e) return;
    int lson=fa*2,rson=lson+1;
    tree[lson].s=tree[fa].s,tree[lson].e=(tree[fa].e+tree[fa].s)/2;
    tree[lson].sumR=sumA[tree[lson].e]-sumA[tree[lson].s-1];

    tree[rson].s=tree[lson].e+1,tree[rson].e=tree[fa].e;
    tree[rson].sumR=sumA[tree[rson].e]-sumA[tree[rson].s-1];
    buildTree(lson);
    buildTree(rson);
}

bool isIntegrate(int x,int y,int fa) {  // 检查两区间是否有交集
    if(x>tree[fa].e) return false;
    if(y<tree[fa].s) return false;
    return true;
}

void modify(int x,int y,long long int k,int fa){
    // 下传lazy标记
    if(lazy[fa]!=0 && tree[fa].s!=tree[fa].e) {
        int lson=fa<<1,rson=lson+1;
        tree[lson].sumR+=(tree[lson].e-tree[lson].s+1)*lazy[fa];
        lazy[lson]+=lazy[fa];
        tree[rson].sumR+=(tree[rson].e-tree[rson].s+1)*lazy[fa];
        lazy[rson]+=lazy[fa];
        lazy[fa]=0;
    }
    if(!isIntegrate(x,y,fa)) {
        return;
    }
    if(tree[fa].s>=x && tree[fa].e<=y) {
        lazy[fa]+=k;
        long long int add=k*(tree[fa].e-tree[fa].s+1);
        tree[fa].sumR+=add;
        while(fa>>=1) {
            tree[fa].sumR+=add;
        }
    }else {
        modify(x,y,k,(fa<<1)+1);
        modify(x,y,k,fa<<1);
    }
}

void search(int x,int y,int fa) {
    // 下传lazy标记
    if(lazy[fa]!=0 && tree[fa].s!=tree[fa].e) {
        int lson=fa<<1,rson=lson+1;
        tree[lson].sumR+=(tree[lson].e-tree[lson].s+1)*lazy[fa];
        lazy[lson]+=lazy[fa];
        tree[rson].sumR+=(tree[rson].e-tree[rson].s+1)*lazy[fa];
        lazy[rson]+=lazy[fa];
        lazy[fa]=0;
    }
    if(!isIntegrate(x,y,fa)) {
        return;
    }
    if(tree[fa].s>=x && tree[fa].e<=y) {
        result+=tree[fa].sumR;
    }else {
        search(x,y,(fa<<1)+1);
        search(x,y,fa<<1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    // 前缀和
    for(int i=1;i<=n;i++) {
        sumA[i]=sumA[i-1]+a[i];
    }
    // build tree
    tree[1].s=1,tree[1].e=n,tree[1].sumR=sumA[n];
    buildTree(1);
    for(int _=1;_<=m;_++) {
        cin>>op>>x>>y;
        if(op==1) {
            cin>>k;
            modify(x,y,k,1);
        }else if(op==2) {
            result=0;
            search(x,y,1);
            cout<<result<<endl;
        }
    }

    // 以下为调试用代码
    cout<<endl;
    for(int i=1;i<=n*4;i++) {
        cout<<tree[i].s<<" "<<tree[i].e<<" "<<tree[i].sumR<<endl;
    }
    cout<<endl;
    cout<<"lazy"<<endl;
    for(int i=1;i<=n*4;i++) {
        cout<<tree[i].s<<" "<<tree[i].e<<" "<<lazy[i]<<endl;
    }
    return 0;
}
// AC https://www.luogu.com.cn/record/176825101
