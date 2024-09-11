#include <iostream>
using namespace std;
//      最大向右扩展量                   悬线长度
int n,m,r[1005][1005],l[1005][1005],down[1005][1005],cnt;
int lmin[1005][1005],rmin[1005][1005],ans;
char maze[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            cin>>maze[i][j];
    }
    // 填充l
    for(int i=1;i<=n;i++) {
        cnt=0;
        for(int j=1;j<=m;j++) {
            if(maze[i][j]=='F')
                cnt+=1,l[i][j]=cnt;
            else
                cnt=0,l[i][j]=cnt;
        }
    }
    // 填充r
    for(int i=1;i<=n;i++) {
        cnt=0;
        for(int j=m;j>=1;j--) {
            if(maze[i][j]=='F')
                cnt+=1,r[i][j]=cnt;
            else
                cnt=0,r[i][j]=cnt;
        }
    }
    // 填充down
    for(int j=1;j<=m;j++) {
        cnt=0;
        for(int i=n;i>=1;i--) {
            if(maze[i][j]=='F')
                cnt+=1,down[i][j]=cnt;
            else
                cnt=0,down[i][j]=cnt;
        }
    }
    // 填充lmin 即由此点向下悬线能够向左走的最大值（因为是每个点向左走最大值的最小值，所以叫lmin）
    for(int j=1;j<=m;j++) {
        cnt=1005;
        for(int i=n;i>=1;i--) {
            if(l[i][j]==0)      // 遇到障碍点如何处理
                cnt=1005,lmin[i][j]=0;
            else
                cnt=min(cnt,l[i][j]),lmin[i][j]=cnt;
        }
    }
    // 填充rmin
    for(int j=1;j<=m;j++) {
        cnt=1005;
        for(int i=n;i>=1;i--) {
            if(r[i][j]==0)      // 遇到障碍点如何处理
                cnt=1005,rmin[i][j]=0;
            else
                cnt=min(cnt,r[i][j]),rmin[i][j]=cnt;
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            ans=max(ans,(lmin[i][j]+rmin[i][j]-1)*down[i][j]);
        }
    }
    cout<<ans*3<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/176053138
