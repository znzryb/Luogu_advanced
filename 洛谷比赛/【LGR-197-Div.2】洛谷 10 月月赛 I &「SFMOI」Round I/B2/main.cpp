#include <iostream>
using namespace std;
typedef long long ll;
ll m,t,x;
const ll mod = static_cast<ll>(1e17)+7;
int main()
{
    cin>>t;
    for(int _=1;_<=t;_++) {
        cout<<"? "<<mod<<endl;
        cout.flush();
        cin>>m;
        cout<<"! "<<m<<endl;
        cout.flush();
    }
    return 0;
}
// 这个是x mod m