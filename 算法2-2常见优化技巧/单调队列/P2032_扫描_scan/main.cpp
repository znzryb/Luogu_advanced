#include <iostream>
#include <queue>
#include <deque>
using namespace std;
const int maxn=2e6+10;
int n,k,a[maxn],maxa;
deque<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }

    for(int i=1;i<=k;i++) {
        // 如果有个比较小的元素夹在两大元素中间，就说明使用不到的，弹出
        while(!q.empty() && a[i]>q.back()) {
            q.pop_back();
        }
        q.push_back(a[i]);
    }
    cout<<q.front()<<endl;
    for(int i=2;i<=n-k+1;i++) {
        if(q.front()==a[i-1]) {
            q.pop_front();
        }
        while(!q.empty() && a[i+k-1]>q.back()) {
            q.pop_back();
        }
        q.push_back(a[i+k-1]);
        cout<<q.front()<<endl;
    }
    return 0;
}
// AC https://www.luogu.com.cn/record/175716408