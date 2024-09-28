#include <iostream>
using namespace std;
const int maxn=2e4+10;
long long int a,b,old[maxn],Newa[maxn],ans;
bool maze[maxn];// 离散化后的模拟
int n,dtop;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=2*n;i+=2) {
        cin>>a>>b;
        old[i]=a;
        old[i+1]=b;
        Newa[i]=a,Newa[i+1]=b;
    }
    sort(&old[1],&old[2*n+1]);
    for(int i=1;i<=2*n;i++) {
        Newa[i]=lower_bound(&old[1],&old[2*n+1],Newa[i])-&old[0];
    }
    for(int i=1;i<=2*n;i++) {
        cout<<Newa[i]<<" ";
    }

    return 0;
}
