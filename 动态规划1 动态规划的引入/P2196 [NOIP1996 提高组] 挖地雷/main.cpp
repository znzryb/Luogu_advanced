#include <iostream>
#include <vector>
// https://www.luogu.com.cn/problem/P2196  DAG
using namespace std;
int n,jud,ansR[25];    // 地雷
long long int mines[25],cnt,ans;
bool vis[25];
vector<int> route;
struct edge {
    vector<int> son;
}g[25];
void dfs(int x) {
    if(g[x].son.empty()) {
        if(cnt>ans) {
            ans=cnt;
            for(int i=1;i<=route.size();i++)
                ansR[i]=route[i-1];
            ansR[route.size()+1]=0;
        }
        return;
    }
    for(auto sonn:g[x].son) {
        if(!vis[sonn]) {
            vis[sonn]=true,cnt+=mines[sonn],route.push_back(sonn);
            dfs(sonn);
            vis[sonn]=false,cnt-=mines[sonn],route.pop_back();
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>mines[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            cin>>jud;
            if(jud)
                g[i].son.push_back(j);
        }
    }
    for(int i=1;i<=n;i++) {
        cnt=mines[i],vis[i]=true,route.push_back(i);
        dfs(i);
        vis[i]=false,route.pop_back();
    }
    for(int i=1;i<=n;i++) {
        if(ansR[i]!=0)
            cout<<ansR[i]<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
// https://www.luogu.com.cn/record/176503271
// hack 数据
// 3
// 10 20 5
// 0 1
// 0
// AC https://www.luogu.com.cn/record/176503964