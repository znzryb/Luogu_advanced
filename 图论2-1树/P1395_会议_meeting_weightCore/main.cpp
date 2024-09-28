#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
const int maxn=5e4+10;
int n,a,b,sonLenM[maxn];    // 最大子树长度
int core,minLenSon=maxn;
long long ans;
vector<int> g[maxn];
bitset<50007> vis;
int dfs(int x,int dis) {
    ans+=dis;
    // cout<<x<<" "<<ans<<endl;
    bool isLeaf=true;
    int accMsonL=0;   // 接受到的子树总长度
    int maxSubtreeLen = 0;
    for(vector<int>::iterator it=g[x].begin();it!=g[x].end();it++) {
        if(vis[*it]==false) {
            vis[*it]=true;
            int sonLen=dfs(*it,dis+1);
            accMsonL+=sonLen;
            maxSubtreeLen = max(maxSubtreeLen, sonLen);
            isLeaf=false;
        }
    }

    // sonLenM[x]=max(accMsonL,n-1-accMsonL);
    // if(isLeaf) {
    //     return 1;
    // } else {
    //     return accMsonL+1;
    // }
    if (isLeaf) {
        sonLenM[x] = n - 1;  // 叶子节点，它的最大子树就是n-1（所有其他点）
        return 1;
    } else {
        sonLenM[x] = max(maxSubtreeLen, n - 1 - accMsonL);  // 最大子树大小
        return accMsonL + 1;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis[1]=true;
    dfs(1,0);
    for(int i=1;i<=n;i++) {
        if(sonLenM[i]<minLenSon)
            core=i,minLenSon=sonLenM[i];
    }
    vis.reset();
    ans=0,vis[core]=true;
    dfs(core,0);
    cout<<core<<" "<<ans<<endl;
    return 0;
}