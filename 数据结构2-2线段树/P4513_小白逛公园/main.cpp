#include <iostream>
#define ll long long
// https://www.luogu.com.cn/problem/P4513
// 这题实际是求区间最大子段和
using namespace std;
const int maxn=5e5+10;const ll canNotReach=-1e18;
ll n,m,x,y,a[maxn],op,mm1;
struct rangeSES {
    ll s;ll e;ll maxR,sum,prefixSum,suffixSum;
}tree[maxn*4];
struct reMSPS {
    ll maxR,sum,prefixSum,suffixSum;
};

void buildTree(ll fa) {  // 填充s e
    if(tree[fa].e==tree[fa].s)  return;
    ll lson=fa<<1,rson=lson+1;
    tree[lson].s=tree[fa].s,tree[lson].e=(tree[fa].s+tree[fa].e)>>1;
    tree[rson].s=tree[lson].e+1,tree[rson].e=tree[fa].e;
    buildTree(lson);
    buildTree(rson);
}
reMSPS fillTree(ll fa) {
    reMSPS re_msps,re_mspsr,re_mspsl;
    if(tree[fa].s==tree[fa].e) {
        tree[fa].sum=tree[fa].prefixSum=tree[fa].maxR=tree[fa].suffixSum=a[tree[fa].s];
        re_msps.sum=re_msps.prefixSum=re_msps.suffixSum=re_msps.maxR=a[tree[fa].s];
        return re_msps;
    }
    ll lson=fa<<1,rson=lson+1;
    re_mspsl=fillTree(lson),re_mspsr=fillTree(rson);
    tree[fa].sum=re_mspsl.sum+re_mspsr.sum;
    tree[fa].prefixSum=max(re_mspsl.sum+re_mspsr.prefixSum,re_mspsl.prefixSum);
    tree[fa].suffixSum=max(re_mspsr.sum+re_mspsl.suffixSum,re_mspsr.suffixSum);
    mm1=max(re_mspsl.maxR,re_mspsr.maxR);
    tree[fa].maxR=max(re_mspsl.suffixSum+re_mspsr.prefixSum,mm1);
    re_msps.maxR=tree[fa].maxR;
    re_msps.suffixSum=tree[fa].suffixSum;
    re_msps.prefixSum=tree[fa].prefixSum;
    re_msps.sum=tree[fa].sum;
    return re_msps;
}
reMSPS search(ll fa) {
    ll lson=fa<<1,rson=lson+1;
    reMSPS re_msps,re_mspsr,re_mspsl;
    bool lJudge=false,rJudge=false;
    if(tree[fa].s>=x && tree[fa].e<=y) {
        re_msps.sum=tree[fa].sum;
        re_msps.maxR=tree[fa].maxR;
        re_msps.prefixSum=tree[fa].prefixSum;
        re_msps.suffixSum=tree[fa].suffixSum;
        return re_msps;
    }
    if(tree[fa].e>=x) {
        if(tree[lson].e>=x)
            re_mspsl=search(lson),lJudge=true;
        if(tree[rson].e>=x)
            re_mspsr=search(rson),rJudge=true;
    }
    if(lJudge && rJudge) {
        re_msps.sum=re_mspsl.sum+re_mspsr.sum;
        re_msps.prefixSum=max(re_mspsl.sum+re_mspsr.prefixSum,re_mspsl.prefixSum);
        re_msps.suffixSum=max(re_mspsr.sum+re_mspsl.suffixSum,re_mspsr.suffixSum);
        mm1=max(re_mspsl.maxR,re_mspsr.maxR);
        re_msps.maxR=max(re_mspsl.suffixSum+re_mspsr.prefixSum,mm1);
        return re_msps;
    }else if(lJudge && !rJudge) {
        return re_mspsl;
    }else if(!lJudge && rJudge){
        return re_mspsr;
    } else {
        re_msps.sum=0;
        re_msps.prefixSum=canNotReach;
        re_msps.suffixSum=canNotReach;
        re_msps.maxR=canNotReach;
        return re_msps;
    }
}
void modify(ll fa) {
    ll lson=fa<<1,rson=lson+1;
    if(tree[fa].e==tree[fa].s && tree[fa].s==x) {
        tree[fa].sum=tree[fa].prefixSum=tree[fa].suffixSum=tree[fa].maxR=y;
        while(fa>>=1) {
            ll sonl=fa<<1,sonr=sonl+1;
            tree[fa].sum=tree[sonl].sum+tree[sonr].sum;
            tree[fa].prefixSum=max(tree[sonl].sum+tree[sonr].prefixSum,tree[sonl].prefixSum);
            tree[fa].suffixSum=max(tree[sonr].sum+tree[sonl].suffixSum,tree[sonr].suffixSum);
            mm1=max(tree[sonl].maxR,tree[sonr].maxR);
            tree[fa].maxR=max(tree[sonl].suffixSum+tree[sonr].prefixSum,mm1);
        }
        return;
    }
    if(tree[fa].e<x || tree[fa].s>x)    return;
    modify(lson);
    modify(rson);
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
    fillTree(1);
    for(int _=1;_<=m;_++) {
        cin>>op>>x>>y;
        if(op==1) {
            cout<<search(1).maxR<<endl;
        }else {
            modify(1);
        }
    }
    // debug
    // for(int i=1;i<=4*n;i++) {
    //     cout<<tree[i].s<<" "<<tree[i].e<<" "<<tree[i].maxR<<" "<<tree[i].sum<<" "<<tree[i].prefixSum<<" "<<tree[i].suffixSum<<endl;
    // }

    return 0;
}
