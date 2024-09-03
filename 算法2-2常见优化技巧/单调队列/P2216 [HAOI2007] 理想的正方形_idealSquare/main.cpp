#include <iostream>
#include <deque>
using namespace std;
int a,b,n;
long long int matrix[1005][1005],maxx[1005][1005],minn[1005][1005],nmax[1005][1005],nmin[1005][1005],ans=1000000005;
deque<long long int> q;
// 按行求最大整数，对maxx按列求最大整数,对行求最小整数，对minn按列求最大整数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>n;
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=b;j++)
            cin>>matrix[i][j];
    }
    // 以上为输入
    // 对maxx进行填充
    for(int i=1;i<=a;i++) {
        q={};       // 对q初始化
        for(int j=1;j<=n;j++) {
            while(!q.empty() && matrix[i][j]>q.back())
                q.pop_back();
            q.push_back(matrix[i][j]);
        }
        maxx[i][1]=q.front();
        for(int j=2;j<=b-n+1;j++) {
            if(matrix[i][j-1]==q.front())
                q.pop_front();
            while(!q.empty() && matrix[i][j+n-1]>q.back())
                q.pop_back();
            q.push_back(matrix[i][j+n-1]);
            maxx[i][j]=q.front();
        }
    }
    // 对minn进行填充
    for(int i=1;i<=a;i++) {
        q={};       // 对q初始化
        for(int j=1;j<=n;j++) {
            while(!q.empty() && matrix[i][j]<q.back())
                q.pop_back();
            q.push_back(matrix[i][j]);
        }
        minn[i][1]=q.front();
        for(int j=2;j<=b-n+1;j++) {
            if(matrix[i][j-1]==q.front())
                q.pop_front();
            while(!q.empty() && matrix[i][j+n-1]<q.back())
                q.pop_back();
            q.push_back(matrix[i][j+n-1]);
            minn[i][j]=q.front();
        }
    }
    // 对minn按列求最小整数
    for(int j=1;j<=b-n+1;j++) {
        q={};       // 对q初始化
        for(int i=1;i<=n;i++) {
            while(!q.empty() && minn[i][j]<q.back())
                q.pop_back();
            q.push_back(minn[i][j]);
        }
        nmin[1][j]=q.front();
        for(int i=2;i<=a-n+1;i++) {
            if(minn[i-1][j]==q.front())
                q.pop_front();
            while(!q.empty() && minn[i+n-1][j]<q.back())
                q.pop_back();
            q.push_back(minn[i+n-1][j]);
            nmin[i][j]=q.front();
        }
    }
    // 对maxx按列求最大整数
    for(int j=1;j<=b-n+1;j++) {
        q={};       // 对q初始化
        for(int i=1;i<=n;i++) {
            while(!q.empty() && maxx[i][j]>q.back())
                q.pop_back();
            q.push_back(maxx[i][j]);
        }
        nmax[1][j]=q.front();
        for(int i=2;i<=a-n+1;i++) {
            if(maxx[i-1][j]==q.front())
                q.pop_front();
            while(!q.empty() && maxx[i+n-1][j]>q.back()) //
                q.pop_back();
            q.push_back(maxx[i+n-1][j]);
            nmax[i][j]=q.front();
        }
    }

    for(int i=1;i<=a-n+1;i++) {
        for(int j=1;j<=b-n+1;j++) {
            ans=min(nmax[i][j]-nmin[i][j],ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/175795092