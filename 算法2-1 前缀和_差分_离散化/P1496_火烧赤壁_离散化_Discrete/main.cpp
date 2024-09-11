#include <iostream>
using namespace std;
const int maxn=2e4+10;
long long int a[maxn],b[maxn],d[maxn];
int n,dtop;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        d[++dtop]=a[i];
        d[++dtop]=b[i];
    }
    sort(&d[1],&d[2*n+1]);
    return 0;
}
