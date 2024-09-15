#include <iostream>
using namespace std;
const int maxn=1e5+10,maxn4=maxn*4;
int n,m,op,x,y,result,lazy[maxn4];
struct rangeSES {
    int s;int e;int num;
}tree[maxn4];
void buildTree(int fa){
    if(tree[fa].s==tree[fa].e)  return;
    int lson=fa<<1;int rson=lson+1;
    tree[lson].s=tree[fa].s,tree[lson].e=(tree[fa].e+tree[fa].s)>>1;
    tree[rson].e=tree[fa].e;tree[rson].s=tree[lson].e+1;
    buildTree(rson);buildTree(lson);
}
void modify(int x,int y,int fa) {
    int lson=fa<<1;int rson=lson+1;
    if(lazy[fa] && tree[fa].s!=tree[fa].e) {
        if(lazy[fa]%2==0) {
            lazy[rson]+=lazy[fa];
            lazy[lson]+=lazy[fa];
        }else {
            lazy[rson]+=lazy[fa];
            lazy[lson]+=lazy[fa];
            tree[rson].num=(tree[rson].e-tree[rson].s+1)-tree[rson].num;
            tree[lson].num=(tree[lson].e-tree[lson].s+1)-tree[lson].num;
        }
        lazy[fa]=0;
    }
    if(x>tree[fa].e or y<tree[fa].s) return;
    if(tree[fa].e<=y && tree[fa].s>=x) {
        int originFaNum=tree[fa].num;
        tree[fa].num=(tree[fa].e-tree[fa].s+1)-tree[fa].num,lazy[fa]+=1;
        int add=tree[fa].num-originFaNum;
        while (fa>>=1) {
            tree[fa].num+=add;
        }
        return;
    }
    modify(x,y,lson);
    modify(x,y,rson);
}

void search(int x,int y,int fa) {
    int lson=fa<<1;int rson=lson+1;
    if(lazy[fa] && tree[fa].s!=tree[fa].e) {
        if(lazy[fa]%2==0) {
            lazy[rson]+=lazy[fa];
            lazy[lson]+=lazy[fa];
        }else {
            lazy[rson]+=lazy[fa];
            lazy[lson]+=lazy[fa];
            tree[rson].num=(tree[rson].e-tree[rson].s+1)-tree[rson].num;
            tree[lson].num=(tree[lson].e-tree[lson].s+1)-tree[lson].num;
        }
        lazy[fa]=0;
    }
    if(x>tree[fa].e or y<tree[fa].s) return;
    if(tree[fa].e<=y && tree[fa].s>=x) {
        result+=tree[fa].num;
        return;
    }
    search(x,y,lson);
    search(x,y,rson);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    tree[1].s=1;tree[1].e=n;tree[1].num=0;
    buildTree(1);
    for(int _=1;_<=m;_++) {
        cin>>op>>x>>y;
        if(op==0) modify(x,y,1);
        else {
            result=0;
            search(x,y,1);
            cout<<result<<endl;
        }
    }
    // debug
    // for(int i=1;i<=n*4;i++) {
    //     cout<<tree[i].s<<" "<<tree[i].e<<" "<<tree[i].num<<endl;
    // }
    return 0;
}
// AC https://www.luogu.com.cn/record/177015865