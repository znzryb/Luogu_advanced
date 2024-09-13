#include <iostream>
// https://www.luogu.com.cn/problem/P3842
// dp
using namespace std;
const int maxn=2e4+10;
int n,dp[maxn],dp2[maxn];     // 这个dp表里存的应该是 从该点出 且 把该行线段走完的最短距离
struct startEnd {
    int s;
    int e;
}se[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>se[i].s>>se[i].e;
    }
    // dp initialize
    for(int i=1;i<=n;i++) {
        if(i==se[1].s)
            dp[se[1].s]=se[1].e-1+se[1].e-se[1].s;
        else if(i==se[1].e)
            dp[se[1].e]=se[1].e-1;
        else
            dp[i]=maxn;
    }
    for(int i=1;i<=n;i++) {
        dp2[i]=dp[i];
    }
    for(int r=2;r<=n;r++) {
        int currS=se[r].s,currE=se[r].e,sUp=se[r-1].s,eUp=se[r-1].e;
        if(eUp>=currE) {
            dp[currS]=dp2[eUp]+eUp-currS;
        }else {
            dp[currS]=dp2[eUp]+currE-currS+currE-eUp;
        }

        if(sUp<=currS) {
            dp[currE]=dp2[sUp]+currE-sUp;
        }else {
            dp[currE]=dp2[sUp]+sUp-currS+currE-currS;
        }

        if(sUp>=currE) {
            dp[currS]=min(dp[currS],dp2[sUp]+sUp-currS);
        }else {
            dp[currS]=min(dp[currS],dp2[sUp]+currE-currS+currE-sUp);
        }

        if(eUp<=currS) {
            dp[currE]=min(dp[currE],dp2[eUp]+currE-eUp);
        }else {
            dp[currE]=min(dp[currE],dp2[eUp]+eUp-currS+currE-currS);
        }
        // dp2缓存
        dp2[currS]=dp[currS],dp2[currE]=dp[currE];
    }
    dp[n]=min(dp[se[n].e]+n-se[n].e,dp[se[n].s]+n-se[n].s);
    // 没计算向下走的步数
    cout<<dp[n]+n-1<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/176665084