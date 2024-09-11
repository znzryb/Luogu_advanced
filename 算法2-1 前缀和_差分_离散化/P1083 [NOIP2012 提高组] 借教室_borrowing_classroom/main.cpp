#include <iostream>
using namespace std;
const int maxn=1e6+10;
int n,m;
long long int r[maxn];
struct dsj {
    long long int d;
    int s;
    int j;
}dsjs[maxn];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>r[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>dsjs[i].d>>dsjs[i].s>>dsjs[i].j;
    }
    return 0;
}
