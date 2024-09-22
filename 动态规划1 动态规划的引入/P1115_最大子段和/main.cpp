#include <iostream>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll dp=0,ans=-100007,a[maxn],n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        dp+=a[i];
        ans=max(ans,dp);
        if(dp<0)
            dp=0;
        // cout<<i<<" : "<<dp<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/177659441
// AC https://www.luogu.com.cn/record/177660309
// 双倍经验