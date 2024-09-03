#include <iostream>
using namespace std;
const int maxn=1e5+10;
int n,w,score[maxn],cnt[605];
int main()
{
    cin>>n>>w;
    for(int i=1;i<=n;i++) {
        cin>>score[i];
    }
    for(int i=1;i<=n;i++) {
        int getPrize=max(1,i*w/100);
        cnt[score[i]]+=1;
        int accumuCnt=0;
        for(int j=600;j>=0;j--) {
            accumuCnt+=cnt[j];
            if(accumuCnt>=getPrize) {
                cout<<j<<" ";
                break;
            }
        }
    }
    return 0;
}



// 插入排序不出所料85.
// #include <iostream>
// #include <set>
// using namespace std;
// const int maxn=1e5+10;
// int n,w,score[maxn];
// multiset<int> curr_score;
// multiset<int>:: iterator itEnd;
// int main()
// {
//     cin>>n>>w;
//     for(int i=1;i<=n;i++) {
//         cin>>score[i];
//     }
//     for(int i=1;i<=n;i++) {
//         int getPrize=max(1,i*w/100);
//         curr_score.insert(score[i]);
//         itEnd=curr_score.end();
//         advance(itEnd,-getPrize);
//         cout<<*itEnd<<" ";
//     }
//     return 0;
// }
// 85 https://www.luogu.com.cn/record/175563851