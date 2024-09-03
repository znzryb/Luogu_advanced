#include <iostream>
#include <vector>
using namespace std;
const int maxn=8e4+10;
long long int n,h[maxn];
unsigned long long int ans;
vector<long long int> stack; // 单调栈
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>h[i];
    }
    if(n==1) {
        cout<<0;
        return 0;
    }
    stack.push_back(h[1]);
    // 统计你能被几只牛看见
    for(int i=2;i<=n;i++) {
        while (!stack.empty() && h[i]>stack.back()) {
            stack.pop_back();
        }
        if(h[i]!=stack.back())
            stack.push_back(h[i]);
        ans+=stack.size()-1;
    }
    cout<<ans<<endl;
    return 0;
}
// 30 pts https://www.luogu.com.cn/record/175644115
// hack 未正确处理相同高度时的情况
// 5
// 3
// 3
// 3
// 1
// 4
// 应输出1
// AC https://www.luogu.com.cn/record/175644351