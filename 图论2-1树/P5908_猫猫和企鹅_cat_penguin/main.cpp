#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n,d,u,v,fa,faDis,ans;
struct nodeDis {
    int sel,dis;
}pushN;
queue<nodeDis> q;
const int maxn=1e5+10;
vector<int> g[maxn];
bool vis[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pushN.dis=0,pushN.sel=1;
    q.push(pushN),vis[1]=true;
    while (!q.empty()) {
        fa=q.front().sel,faDis=q.front().dis;
        q.pop();
        for(vector<int>::iterator i=g[fa].begin();i!=g[fa].end();i++) {
            if(vis[*i]==false) {
                pushN.dis=faDis+1,pushN.sel=*i;
                if(faDis+1<=d) ans+=1,q.push(pushN);
                vis[*i]=true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/177953710