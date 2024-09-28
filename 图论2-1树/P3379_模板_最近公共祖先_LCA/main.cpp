#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;
const int maxn=500007;
int n,m,root,a,b,dep[maxn],lg[maxn],pa[maxn][24];   // 2^0 2^1 2^2....的parent
bool vis[maxn];
vector<int> g[maxn];
void dfs(int x,int deep,int fa) {       // O(nlogn)
    dep[x]=deep;
    pa[x][0]=fa;
    for(int j=1;j<=lg[deep];j++) {
        pa[x][j]=pa[pa[x][j-1]][j-1];   // 2^i = 2^(i-1) + 2^(i-1)  [j-1]是指提升2^(j-1)
    }
    for(int i=0;i<g[x].size();i++) {
        int son=g[x][i];
        if(!vis[son]) {
            vis[son]=true;
            dfs(son,deep+1,x);
        }
    }
}
int query(int a,int b) {
    if(dep[a]>dep[b])
        swap(a,b);
    while (dep[b]!=dep[a])
        b=pa[b][lg[dep[b]-dep[a]]-1];   // 提升高度其实可以知道
    if(a==b)
        return a;
    for(int i=lg[dep[a]];i>=0;--i) {
        if(pa[a][i]!=pa[b][i]) {
            a=pa[a][i],b=pa[b][i];
        }
    }
    return pa[a][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>root;
    for(int i=1;i<=n-1;i++) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;++i) {
        lg[i]=lg[i-1]+(1 << lg[i-1] == i);  // 0 1 2 2 3 3 3
    }
    vis[root]=true;
    dfs(root,0,0);
    for(int _=1;_<=m;++_) {
        cin>>a>>b;
        cout<<query(a,b)<<endl;
    }
    // debug
    // for(int i=1;i<=n;i++) {
    //     for(int j=0;j<10;j++)
    //         cout<<pa[i][j]<<" ";
    //     cout<<endl;
    // }
    return 0;
}
// AC https://www.luogu.com.cn/record/178901945