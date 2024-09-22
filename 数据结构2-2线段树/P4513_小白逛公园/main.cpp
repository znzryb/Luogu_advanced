#include <iostream>
#define ll long long
// https://www.luogu.com.cn/problem/P4513
// 这题实际是求区间最大子段和
using namespace std;
const int maxn=5e5+10;
ll n,m,x,y,a[maxn],op;
struct rangeSES {
    ll s;ll e;ll maxR;
}tree[maxn*4];
void buildTree(ll fa) {  // 填充s e
    if(tree[fa].e==tree[fa].s)  return;
    ll lson=fa<<1,rson=lson+1;
    tree[lson].s=tree[fa].s,tree[lson].e=(tree[fa].s+tree[fa].e)>>1;
    tree[rson].s=tree[lson].e+1,tree[rson].e=tree[fa].e;
    buildTree(lson);
    buildTree(rson);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    tree[1].s=1,tree[1].e=n;
    buildTree(1);
    for(int _=1;_<=m;_++) {
        cin>>op>>x>>y;
    }
    // debug
    for(int i=1;i<=4*n;i++) {
        cout<<tree[i].s<<" "<<tree[i].e<<" "<<tree[i].maxR<<endl;
    }
    return 0;
}
