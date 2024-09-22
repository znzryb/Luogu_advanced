#include <iostream>
#define ll long long
using namespace std;
const ll maxn=1e6+10,maxn4=maxn*4,canNotReach=1e17+171614;
ll n,q,op,l,r,x,a[maxn],tagToX[maxn4],tagAddX[maxn4],result;
struct rangeSES {
    ll s;ll e;ll maxR;
}tree[maxn4];
void buildTree(ll fa) {     // 其实只是搭了个s，e框架
    if(tree[fa].s==tree[fa].e)  return;
    ll lson=fa<<1,rson=lson+1;
    tree[lson].s=tree[fa].s;tree[lson].e=(tree[fa].e+tree[fa].s)/2;
    tree[rson].s=tree[lson].e+1;tree[rson].e=tree[fa].e;
    buildTree(lson);
    buildTree(rson);
}
ll fillmaxR(ll fa) {    // 使用dfs fillSumR
    if(tree[fa].s==tree[fa].e) {
        tree[fa].maxR=a[tree[fa].s];
        return a[tree[fa].s];
    }
    ll lson=fa<<1,rson=lson+1;
    ll lSonMax=fillmaxR(lson);
    ll rSonMax=fillmaxR(rson);
    tree[fa].maxR=max(rSonMax,lSonMax);
    return tree[fa].maxR;
}
inline void pushdownToX(ll fa) {   // cover 函数
    if(tagToX[fa]==canNotReach) return;
    ll lson=fa<<1,rson=lson+1;
    tree[lson].maxR=tree[rson].maxR=tagToX[fa];
    tagToX[lson]=tagToX[rson]=tagToX[fa];
    // 下传tagToX标记时，发现tagAddX有东西，说明这个tagAdd是之前加的，否则我的tagTo已经传完了
    tagAddX[lson]=tagAddX[rson]=0;
    tagToX[fa]=canNotReach;
}
inline void pushdownAddX(ll fa) {
    if(tagAddX[fa]==0)  return;
    ll lson=fa<<1,rson=lson+1;
    // if(tagToX[fa]!=canNotReach) return;
    tree[lson].maxR+=tagAddX[fa],tree[rson].maxR+=tagAddX[fa];
    tagAddX[lson]+=tagAddX[fa],tagAddX[rson]+=tagAddX[fa];
    tagAddX[fa]=0;
}
void modifyToX(ll fa,ll l,ll r,ll x) {
    if(tree[fa].e<l or r<tree[fa].s) return;
    ll lson=fa<<1,rson=lson+1;
    // 下传tag标记
    if(tree[fa].s!=tree[fa].e) {    // 一旦遍历到立即下传，以免出现覆盖等情况
        pushdownToX(fa);
        pushdownAddX(fa);
    }
    if(l<=tree[fa].s && tree[fa].e<=r) {
        tree[fa].maxR=x;
        tagToX[fa]=x; // 一旦发生to x更改，原来的Add懒标记就没用了
        // 上传更改
        while (fa>>=1) {
            ll sonl=fa<<1,sonr=sonl+1;
            tree[fa].maxR=max(tree[sonl].maxR,tree[sonr].maxR);
        }
        return;
    }
    if(tree[lson].e>=l)modifyToX(lson,l,r,x);
    if(tree[rson].s<=r)modifyToX(rson,l,r,x);
}
void modifyAddX(ll fa,ll l,ll r,ll x) {
    if(tree[fa].e<l or r<tree[fa].s) return;
    ll lson=fa<<1,rson=lson+1;
    // 下传tag标记
    if(tree[fa].s!=tree[fa].e) {
        pushdownToX(fa);
        pushdownAddX(fa);
    }
    if(l<=tree[fa].s && tree[fa].e<=r) {
        tree[fa].maxR+=x;
        tagAddX[fa]+=x;
        // 上传更改
        while (fa>>=1) {
            ll sonl=fa<<1,sonr=sonl+1;
            tree[fa].maxR=max(tree[sonl].maxR,tree[sonr].maxR);
        }
        return;
    }
    if(tree[lson].e>=l)modifyAddX(lson,l,r,x);
    if(tree[rson].s<=r)modifyAddX(rson,l,r,x);
}
void search(ll fa,ll l,ll r) {
    if(tree[fa].e<l or r<tree[fa].s) return;
    ll lson=fa<<1,rson=lson+1;
    // 下传tag标记
    if(tree[fa].s!=tree[fa].e) {
        pushdownToX(fa);
        pushdownAddX(fa);
    }
    if(l<=tree[fa].s && tree[fa].e<=r) {
        result=max(result,tree[fa].maxR);
        return;
    }
    if(tree[lson].e>=l) search(lson,l,r);
    if(tree[rson].s<=r) search(rson,l,r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    fill(&tagToX[1],&tagToX[4*n],canNotReach);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    // 建树
    tree[1].e=n,tree[1].s=1;
    buildTree(1);
    tree[1].maxR=fillmaxR(1);
    for(int i=1;i<=q;i++) {
        cin>>op>>l>>r;
        if(op==1) {
            cin>>x;
            modifyToX(1,l,r,x);
        }else if(op==2) {
            cin>>x;
            modifyAddX(1,l,r,x);
        }else {
            result=-canNotReach;
            search(1,l,r);
            cout<<result<<endl;
        }
    }
    // debug
    // for(int i=1;i<=4*n;i++) {
    //     cout<<tree[i].s<<" "<<tree[i].e<<" "<<tree[i].maxR<<endl;
    // }
    return 0;
}
// 20pts https://www.luogu.com.cn/record/177185980
// 对代码进行了模块化操作
// 50pts https://www.luogu.com.cn/record/177259395
// 对代码canNotReach的值进行了更改
// 60pts https://www.luogu.com.cn/record/177270390
// https://www.luogu.com.cn/discuss/923599
// 把下传tag标记放到了前面
// 90pts https://www.luogu.com.cn/record/177276271 TLE了一个点
// 在pushDownAddX和pushDownToX前面加了inline
// AC https://www.luogu.com.cn/record/177277092