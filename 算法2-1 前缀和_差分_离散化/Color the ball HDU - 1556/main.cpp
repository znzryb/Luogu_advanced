#include <iostream>
typedef long long ll;
using namespace std;
const int maxn=100007;
int n,a,b,D[maxn],A[maxn];
int main()
{
    while (true) {
        cin>>n;
        if(n==0)
            break;
        fill(&A[1],&A[n+1],0);
        fill(&D[1],&D[n+1],0);
        for(int i=1;i<=n;i++) {
            cin>>a>>b;
            D[a]+=1,D[b+1]-=1;
        }
        for(int i=1;i<=n;i++) {
            A[i]=A[i-1]+D[i];
        }
        for(int i=1;i<=n;i++) {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// AC http://vjudge.net/solution/54535530