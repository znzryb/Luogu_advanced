#include <iostream>
#include <cmath>
using namespace std;
long long int n,k,freq[100005],sumSiz,cnt;
bool great(long long int a,long long int b) {
    if(a!=b) return a>b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>freq[i];
    }
    sort(&freq[1],&freq[n+1],great);
    for(int i=1;i<=n;i++) {
        if(i%k==0)
            cnt=i/k;
        else
            cnt=i/k+1;
        sumSiz+=freq[i]*cnt;
    }
    cout<<sumSiz<<endl;
    return 0;
}
