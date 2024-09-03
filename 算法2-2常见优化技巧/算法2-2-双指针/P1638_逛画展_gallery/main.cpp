#include <iostream>
using namespace std;
const int maxn=1e6+10,maxm=2e3+10;
int n,m,pic[maxn],painCnt[maxm],l,r,kindCnt,ans=maxn,lans,rans,rup;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>pic[i];
    }
    l=r=1;
    while (l<=r && r<=n) {
        if(painCnt[pic[r]]==0) {
            kindCnt+=1;
        }
        if(r!=rup) {
            painCnt[pic[r]]+=1;
            rup=r;
        }
        if(kindCnt==m) {
            if((r-l+1)<ans)
                lans=l,rans=r,ans=(r-l+1);
            l++;
            painCnt[pic[l-1]]-=1;
            if(painCnt[pic[l-1]]==0)
                kindCnt-=1;
        }else {
            r++;
        }
    }
    cout<<lans<<" "<<rans<<endl;
    return 0;
}
// 思路为区间伸缩
// 73 https://www.luogu.com.cn/record/175402081 错的原因是右端点重复计数
// AC https://www.luogu.com.cn/record/175405213