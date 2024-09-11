#include <iostream>
#include <deque>
using namespace std;
deque<long long int> hs;   // h stack
const int maxn=1e5+10;
long long int h[maxn],ans,minH;
int l[maxn],r[maxn],n,cnt;
// 悬线法
int main()
{
    while(true) {
        ans=0;
        cin>>n;
        fill(&r[0],&r[n+1],0);
        fill(&l[0],&l[n+1],0);
        if(n==0)
            break;
        for(int i=1;i<=n;i++) {
            cin>>h[i];
        }
        r[n]=1,h[n+1]=-1;
        for(int i=n-1;i>0;i--) {
            for(int j=i+1;j<=n+1;j++) {   // j直接表示i悬线能到达的地方
                if(h[i]>h[j]) {
                    r[i]=j-i;
                    break;
                }else {
                    j+=r[j]-1;
                }
            }
        }
        l[1]=1,h[0]=-1;
        for(int i=2;i<=n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(h[i]>h[j]) {
                    l[i]=i-j;
                    break;
                }else {
                    j-=l[j]-1;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            ans=max(ans,(l[i]+r[i]-1)*h[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
// AC https://www.luogu.com.cn/record/175883811
// AC https://vjudge.net.cn/solution/53967042