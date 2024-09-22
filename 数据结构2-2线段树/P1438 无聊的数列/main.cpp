#include <iostream>
#define ll long long
using namespace std;
ll n,m,op,x,y,p;
const int maxn=1e5+10,maxn4=4*maxn;
long long int a[maxn],sumA[maxn],k,d,result,lazyD[maxn4],lazyS[maxn4];
struct rangeSES {
    long long int s;long long int e;long long int sumR;
}tree[maxn4];
void buildTree(ll fa) {
    if(tree[fa].s==tree[fa].e) return;
    ll lson=fa*2,rson=lson+1;
    tree[lson].s=tree[fa].s,tree[lson].e=(tree[fa].e+tree[fa].s)/2;
    tree[lson].sumR=sumA[tree[lson].e]-sumA[tree[lson].s-1];
    tree[rson].s=tree[lson].e+1,tree[rson].e=tree[fa].e;
    tree[rson].sumR=sumA[tree[rson].e]-sumA[tree[rson].s-1];
    buildTree(lson);
    buildTree(rson);
}

bool isIntegrate(ll x,ll y,ll fa) {  // 检查两区间是否有交集
    if(x>tree[fa].e) return false;
    if(y<tree[fa].s) return false;
    return true;
}

void modify(ll x,ll y,long long int k,long long int d,ll fa){
    if(!isIntegrate(x,y,fa)) {
        return;
    }
    // 下传lazy标记
    if((lazyS[fa]!=0 || lazyD[fa]!=0) && tree[fa].s!=tree[fa].e) {
        ll lson=fa<<1,rson=lson+1;
        long long lsonS=lazyS[fa]+(tree[lson].s-tree[fa].s)*lazyD[fa];
        long long lsonE=lazyS[fa]+(tree[lson].e-tree[fa].s)*lazyD[fa];
        long long rsonS=lazyS[fa]+(tree[rson].s-tree[fa].s)*lazyD[fa];
        long long rsonE=lazyS[fa]+(tree[rson].e-tree[fa].s)*lazyD[fa];
        tree[lson].sumR+=(lsonS+lsonE)*(tree[lson].e-tree[lson].s+1)/2;
        tree[rson].sumR+=(rsonS+rsonE)*(tree[rson].e-tree[rson].s+1)/2;
        // cout<<tree[lson].s<<" "<<tree[lson].e<<" "<<((lsonS+lsonE)*(tree[lson].e-tree[lson].s+1)/2)<<endl;
        // cout<<tree[rson].s<<" "<<tree[rson].e<<" "<<((rsonS+rsonE)*(tree[lson].e-tree[lson].s+1)/2)<<endl;
        lazyD[lson]+=lazyD[fa],lazyS[lson]+=lsonS;
        lazyD[rson]+=lazyD[fa],lazyS[rson]+=rsonS;
        lazyD[fa]=0,lazyS[fa]=0;
    }
    if(tree[fa].s>=x && tree[fa].e<=y) {
        long long faS=k+d*(tree[fa].s-x),faE=k+d*(tree[fa].e-x);
        lazyD[fa]+=d,lazyS[fa]+=faS;
        long long int add=(faE+faS)*(tree[fa].e-tree[fa].s+1)/2;
        tree[fa].sumR+=add;
        // cout<<tree[fa].s<<" "<<tree[fa].e<<" "<<add<<endl; // add 是对的
        while(fa>>=1) {
            tree[fa].sumR+=add;
        }
    }else {
        modify(x,y,k,d,(fa<<1)+1);
        modify(x,y,k,d,fa<<1);
    }
}

void search(ll x,ll y,ll fa) {
    if(!isIntegrate(x,y,fa)) {
        return;
    }
    // 下传lazy标记
    if((lazyS[fa]!=0 || lazyD[fa]!=0) && tree[fa].s!=tree[fa].e) {
        ll lson=fa<<1,rson=lson+1;
        long long lsonS=lazyS[fa]+(tree[lson].s-tree[fa].s)*lazyD[fa];
        long long lsonE=lazyS[fa]+(tree[lson].e-tree[fa].s)*lazyD[fa];
        long long rsonS=lazyS[fa]+(tree[rson].s-tree[fa].s)*lazyD[fa];
        long long rsonE=lazyS[fa]+(tree[rson].e-tree[fa].s)*lazyD[fa];
        tree[lson].sumR+=(lsonS+lsonE)*(tree[lson].e-tree[lson].s+1)/2;
        tree[rson].sumR+=(rsonS+rsonE)*(tree[rson].e-tree[rson].s+1)/2;
        // cout<<tree[lson].s<<" "<<tree[lson].e<<" "<<((lsonS+lsonE)*(tree[lson].e-tree[lson].s+1)/2)<<endl;
        // cout<<tree[rson].s<<" "<<tree[rson].e<<" "<<((rsonS+rsonE)*(tree[lson].e-tree[lson].s+1)/2)<<endl;
        lazyD[lson]+=lazyD[fa],lazyS[lson]+=lsonS;
        lazyD[rson]+=lazyD[fa],lazyS[rson]+=rsonS;
        lazyD[fa]=0,lazyS[fa]=0;
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
        cin>>op;
        if(op==1) {
            cin>>x>>y>>k>>d;
            modify(x,y,k,d,1);
        }else if(op==2) {
            cin>>p;
            result=0;
            search(p,p,1);
            cout<<result<<endl;
        }
    }
    // 以下为调试用代码
    // cout<<endl;
    // for(int i=1;i<=n*4;i++) {
    //     cout<<tree[i].s<<" "<<tree[i].e<<" "<<tree[i].sumR<<endl;
    // }
    // cout<<endl;
    // cout<<"lazy"<<endl;
    // for(int i=1;i<=n*4;i++) {
    //     cout<<tree[i].s<<" "<<tree[i].e<<" "<<lazy[i]<<endl;
    // }
    return 0;
}
// 45 https://www.luogu.com.cn/record/177105061
// AC https://www.luogu.com.cn/record/177170002