#include <iostream>
using namespace std;
typedef long long ll;
const int maxk=2e5+10;
ll n,m,k,xy[maxk][2],ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>k;
    // if(n==m && m==1) {
    //     for(int i=0;i<k;i++) {
    //         cin>>xy[i][0]>>xy[i][1];
    //         if(xy[i][0]<xy[i][1]) {ans+=1;}
    //     }
    //     cout<<k<<endl;
    //     return 0;
    // }
    for(int i=0;i<k;i++) {
        cin>>xy[i][0]>>xy[i][1];
        if(xy[i][0]<=xy[i][1]) {ans+=1;}
    }
    cout<<ans<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/179461181