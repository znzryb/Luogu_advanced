#include <iostream>
#include <vector>
using namespace std;
const int mod=1e6+7;
int n,m,a[105],ans,vis[105];     // 第i种花不能超过ai盆
vector<int> perm;
// 先写个dfs
void dfs(int x,int cnt) {
    if(cnt==m) {
        ans=(ans+1)%mod;
        for(auto ch:perm)
            cout<<ch<<" ";
        cout<<endl;
        return;
    }
    for(int i=x;i>=1;i--) {
        if(vis[i]>0) {
            vis[i]-=1,perm.push_back(i);
            dfs(i,cnt+1);
            vis[i]+=1,perm.pop_back();
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        vis[i]=a[i];
    }
    for(int i=n;i>=1;i--) {
        if(vis[i]==0)
            continue;
        vis[i]-=1,perm.push_back(i);
        dfs(i,1);
        vis[i]+=1,perm.pop_back();
    }
    cout<<ans<<endl;
    return 0;
}
// 40 https://www.luogu.com.cn/record/176525577
// 3 4
// 3 2 1

// 3 2 2 1
// 3 2 1 1
// 3 1 1 1
// 2 2 1 1
// 2 1 1 1
// 5