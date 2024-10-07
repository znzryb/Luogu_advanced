#include <iostream>
#include <bitset>
using namespace std;
const int maxn=2e5+10;
int n,m,l[maxn],r[maxn];
char a[maxn],b[maxn],c[maxn];
// bool vis[maxn];
void out() {
    for(int i=1;i<=n;i++) {
        cout<<c[i];
    }
    cout<<endl;
}
inline void compare(){
    for(int i=1;i<=n;i++) {
        if(c[i]>a[i])
            break;
        if(a[i]>c[i]) {
            for(int j=1;j<=n;j++) {
                c[j]=a[j];
            }
            break;
        }
    }
}
void dfs(int x) {
    // out();
    // compare();
    if(x>m)
        return;
    for(int i=l[x];i<=r[x];i++) {
        swap(a[i],b[i]);
    }
    compare();
    dfs(x+1);
    for(int i=l[x];i<=r[x];i++) {
        swap(a[i],b[i]);
    }
    // compare();
    dfs(x+1);
}
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
        cin>>l[_]>>r[_]; // bool isSwap=false;
        // for(int i=l;i<=r;i++) {
        //     if(a[i]>b[i]) break;
        //     if(b[i]>a[i]) {isSwap=true;break;}
        // }
        // if(isSwap) {
        //     for(int i=l;i<=r;i++) swap(a[i],b[i]);
        // }
    }
    for(int i=1;i<=n;i++)
        c[i]=a[i];
    dfs(1);
    for(int i=1;i<=n;i++) {
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}
// https://www.luogu.com.cn/record/179510631 20pts 前面因为低级错误卡了很久，写嵌套for语句要当心
