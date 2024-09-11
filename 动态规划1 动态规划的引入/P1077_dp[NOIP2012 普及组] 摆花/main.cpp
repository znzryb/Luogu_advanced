#include <iostream>
using namespace std;
const int mod=1e6+7;
int n,m,a[105],dp[105][105],maxUp;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=n;i++) {
        maxUp=min(maxUp+a[i],m);
        for(int j=1;j<=maxUp;j++) {
            if(i==1)
                dp[i][j]=1;
            else {
                for(int k=j-min(a[i],j);k<=j-1;k++) {
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                }
                dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/176557022