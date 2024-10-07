#include <iostream>
using namespace std;
const int maxn=2e5+10;
int n,m,l,r;
char a[maxn],b[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
    }
    for(int _=1;_<=m;_++) {
        cin>>l>>r;bool isSwap=false;
        for(int i=l;i<=r;i++) {
            if(a[i]>b[i]) break;
            if(b[i]>a[i]) {isSwap=true;break;}
        }
        if(isSwap) {
            for(int i=l;i<=r;i++) swap(a[i],b[i]);
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
