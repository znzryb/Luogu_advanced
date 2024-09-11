#include <iostream>
using namespace std;
// 记忆化搜索
int r,c,h[105][105],memo[105][105],df[5]={0,1,0,-1},ds[5]={1,0,-1,0},ans;
int dfs(int f,int s) {
    if(memo[f][s]!=0)
        return memo[f][s]+1;
    bool judEnd=true;
    for(int i=0;i<4;i++) {
        if(h[f][s]>h[f+df[i]][s+ds[i]] && f+df[i]>=1 && f+df[i]<=r && s+ds[i]>=1 && s+ds[i]<=c) {
            memo[f][s]=max(dfs(f+df[i],s+ds[i]),memo[f][s]);
            judEnd=false;
        }
    }
    if(judEnd) {
        memo[f][s]=1;
        return 2;
    }else {
        return memo[f][s]+1;
    }
}
int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++)
            cin>>h[i][j];
    }
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            dfs(i,j);
        }
    }
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            ans=max(ans,memo[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/176513870