#include <iostream>
using namespace std;
const int maxn=2e5+10;
const long long int minSum=-2e9;
int n,a[maxn],l,r,lans,rans,rup;
long long int summ=0,maxSum=minSum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    l=r=1;
    while(l<=r && r<=n) {
        if(rup!=r) {
            summ+=a[r];
            rup=r;
        }
        if()

    }
    return 0;
}
