#include <iostream>
using namespace std;
const int maxn=1e6+10;
int heap[maxn],n,op,x,hiz;
void push(int x) {
    int now=hiz+1;
    heap[now]=x;
    int fa=now>>1;
    while(heap[fa]>x) {
        heap[now]=heap[fa];
        heap[fa]=x;
        fa=fa>>1;
        now=now>>1;
    }
}
bool check(int now,int nxt) {
    if(nxt>=hiz) {
        return false;
    }else if(nxt+1>=hiz) {
        if(heap[now]<heap[nxt])
            return false;
        else
            return true;
    }else {
        if(heap[now]<heap[nxt] && heap[now]<heap[nxt+1]) {
            return false;
        }else {
            return true;
        }
    }
}
void pop() {
    if(hiz==0)
        return;
    swap(heap[1],heap[hiz]);
    int now=1,nxt=2;
    //   不满足小根堆性质时才继续    不是叶子节点时才继续
    while(check(now,nxt)) {
        if(heap[nxt]<=heap[nxt+1] or nxt+1>=hiz) {
            swap(heap[now],heap[nxt]);
            now=nxt;
        }else {
            swap(heap[now],heap[nxt+1]);
            now=nxt+1;
        }
        nxt=now<<1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) {     //i==23 error
        cin>>op;
        if(op==1) {
            cin>>x;
            push(x),hiz++;
        }else if(op==2) {
            cout<<heap[1]<<endl;
        }else {
            pop();
            hiz--;
        }
    }
    return 0;
}
// AC https://www.luogu.com.cn/record/176771685