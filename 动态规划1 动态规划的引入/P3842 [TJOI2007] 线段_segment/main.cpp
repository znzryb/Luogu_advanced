#include <iostream>
// https://www.luogu.com.cn/problem/P3842
// dp
using namespace std;
const int maxn=2e4+10;
int n,dp[maxn];
struct startEnd {
    int s;
    int e;
}se[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<-n;i++) {
        cin>>se[i].s>>se[i].e;
    }
    // dp initialize
    for(int i=1;i<=n;i++) {
        dp[i]=i;
    }

    return 0;
}
