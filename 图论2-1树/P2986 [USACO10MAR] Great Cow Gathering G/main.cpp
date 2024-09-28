#include <iostream>
#include <vector>
#include <bitset>
#define ll long long
using namespace std;
const int maxn = static_cast<int>(1e5) + 7;
const long long MAXSON=1e18+7;
int n,a,b,l,core;
int c[maxn];
long long maxSonTree[maxn],minSon=MAXSON;
bitset</*100007*/ maxn> vis;
vector<pair<int,int> > g[maxn];
long long ans,sumN;
long long dfs(ll x,ll dis) {
    long long accSon=0,maxSon=0,treeSon;
    for(int i=0;i<g[x].size();i++) {
        ll son=g[x][i].first,len=g[x][i].second;
        if(!vis[son]) {
            vis[son]=true;
            treeSon=dfs(son,dis+len);
            accSon+=treeSon;
            maxSon=max(maxSon,treeSon);
        }
    }
    maxSon = max(maxSon,sumN-accSon-c[x]);   //accSon>sumN-accSon-c[x] ? accSon:sumN-accSon-c[x];
    maxSonTree[x]=maxSon;
    return accSon+c[x];
}

void dfs2(ll x,ll dis) {   // 统计不方便值的
    ans+=(c[x]*dis);
    for(int i=0;i<g[x].size();i++) {
        ll son=g[x][i].first,len=g[x][i].second;
        if(!vis[son]) {
            vis[son]=true;
            dfs2(son,dis+len);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        sumN+=c[i];
    }
    for(int i=1;i<=n-1;i++) {
        cin>>a>>b>>l;
        // sumN+=l;
        g[a].push_back(make_pair(b,l));
        g[b].push_back(make_pair(a,l));
    }
    vis[1]=true;
    dfs(1,0);
    for(int i=1;i<=n;i++) {
        if(maxSonTree[i]<minSon)
            core=i,minSon=maxSonTree[i];
    }
    vis.reset(),ans=0;
    vis[core]=true;
    dfs2(core,0);
    cout<<ans<<endl;
    return 0;
}
// 30pts https://www.luogu.com.cn/record/178572159
// 40pts https://www.luogu.com.cn/record/178576100  删除了边权，但好像有点不对
// 遇到都read 0的情况大概率不是算法有问题，很有可能是某个min变量的初始值设小了
// 90pts https://www.luogu.com.cn/record/178578870 接近了
// 100pts https://www.luogu.com.cn/record/178579334