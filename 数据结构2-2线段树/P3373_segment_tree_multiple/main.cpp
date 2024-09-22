#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const ll maxn=1e5+10,maxn4=4*maxn;
ll n,q,m,a[maxn],sumA[maxn],lazyA[maxn4],lazyM[maxn4],op,x,y,k,result;
struct rangeSES {
    ll s;ll e;ll sumR;
}tree[maxn4];
void buildTree(ll fa) {
    if(tree[fa].e==tree[fa].s) return;
    ll lson=fa<<1,rson=lson+1;
    tree[lson].s=tree[fa].s,tree[lson].e=(tree[fa].s+tree[fa].e)/2;
    tree[lson].sumR=(sumA[tree[lson].e]-sumA[tree[lson].s-1]+m)%m;
    tree[rson].s=tree[lson].e+1,tree[rson].e=tree[fa].e;
    tree[rson].sumR=(sumA[tree[rson].e]-sumA[tree[rson].s-1]+m)%m;
    buildTree(lson);
    buildTree(rson);
}
inline void pushDownAdd(ll fa) {
    if(lazyA[fa]==0) return;
    ll lson=fa<<1,rson=lson+1,lrange=tree[lson].e-tree[lson].s+1,rrange=tree[rson].e-tree[rson].s+1;
    tree[lson].sumR=(tree[lson].sumR+lazyA[fa]*lrange+m)%m;
    tree[rson].sumR=(tree[rson].sumR+lazyA[fa]*rrange+m)%m;
    lazyA[lson]=(lazyA[lson]+lazyA[fa]+m)%m;
    lazyA[rson]=(lazyA[rson]+lazyA[fa]+m)%m;
    lazyA[fa]=0;
}
inline void pushDownMuitiple(ll fa) {
    if(lazyM[fa]==1) return;
    ll lson=fa<<1,rson=lson+1;
    tree[lson].sumR=(tree[lson].sumR*lazyM[fa]+m)%m;
    tree[rson].sumR=(tree[rson].sumR*lazyM[fa]+m)%m;
    lazyM[lson]=(lazyM[lson]*lazyM[fa]+m)%m,lazyA[lson]=(lazyA[lson]*lazyM[fa]+m)%m;
    lazyM[rson]=(lazyM[rson]*lazyM[fa]+m)%m,lazyA[rson]=(lazyA[rson]*lazyM[fa]+m)%m;
    lazyM[fa]=1;
}
void multiple(ll fa,ll x,ll y,ll k) {
    if(tree[fa].s>y or tree[fa].e<x) return;
    ll lson=fa<<1,rson=lson+1;
    if(tree[fa].e!=tree[fa].s) {
        pushDownMuitiple(fa);
        pushDownAdd(fa);
    }
    if(tree[fa].s>=x && tree[fa].e<=y) {
        ll originSumR=tree[fa].sumR;
        tree[fa].sumR=(tree[fa].sumR*k+m)%m;
        ll add=(tree[fa].sumR-originSumR+m)%m;
        lazyM[fa]=(lazyM[fa]*k+m)%m;lazyA[fa]=(lazyA[fa]*k+m)%m;
        while (fa>>=1) {
            tree[fa].sumR=(tree[fa].sumR+add+m)%m;
        }
        return;
    }
    multiple(lson,x,y,k);
    multiple(rson,x,y,k);
}
void Add(ll fa,ll x,ll y,ll k) {
    if(tree[fa].s>y or tree[fa].e<x) return;
    ll lson=fa<<1,rson=lson+1;
    if(tree[fa].e!=tree[fa].s) {
        pushDownMuitiple(fa);
        pushDownAdd(fa);
    }
    if(tree[fa].s>=x && tree[fa].e<=y) {
        ll originSumR=tree[fa].sumR,lrange=tree[fa].e-tree[fa].s+1;
        tree[fa].sumR=(tree[fa].sumR+k*lrange+m)%m;
        ll add=(tree[fa].sumR-originSumR+m)%m;
        lazyA[fa]=(lazyA[fa]+k+m)%m;
        while (fa>>=1) {
            tree[fa].sumR=(tree[fa].sumR+add+m)%m;
        }
        return;
    }
    Add(lson,x,y,k);
    Add(rson,x,y,k);
}
void search(ll fa,ll x,ll y) {
    if(tree[fa].s>y or tree[fa].e<x) return;
    ll lson=fa<<1,rson=lson+1;
    if(tree[fa].e!=tree[fa].s) {
        pushDownMuitiple(fa);
        pushDownAdd(fa);
    }
    if(tree[fa].s>=x && tree[fa].e<=y) {
        result=(result+tree[fa].sumR+m)%m;
        return;
    }
    search(lson,x,y);
    search(rson,x,y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q>>m;
    fill(&lazyM[1],&lazyM[4*n+1],1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]=(a[i]+m)%m;
    }
    for(int i=1;i<=n;i++) {
        sumA[i]=(a[i]+sumA[i-1]+m)%m;
    }
    tree[1].s=1;tree[1].e=n;tree[1].sumR=sumA[n];
    buildTree(1);
    for(int _=1;_<=q;_++) {
        cin>>op>>x>>y;
        if(op==1) {
            cin>>k;
            multiple(1,x,y,k);
        }else if(op==2) {
            cin>>k;
            Add(1,x,y,k);
        }else {
            result=0;
            search(1,x,y);
            result=(result+m)%m;
            cout<<result<<endl;
        }
    }
    // debug
    // for(int i=1;i<=4*n;i++) {
    //     cout<<tree[i].s<<" "<<tree[i].e<<" "<<tree[i].sumR<<endl;
    // }
    return 0;
}
// 0pts https://www.luogu.com.cn/record/177381805
// 区间加有点问题
// 30pts https://www.luogu.com.cn/record/177381859
// 改了取模算法
// AC https://www.luogu.com.cn/record/177481404