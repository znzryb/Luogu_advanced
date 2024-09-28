#include <iostream>
#include <vector>
#include <deque>
using namespace std;    //                   记录路径 支路路径长度                   记录直径及其先后顺序
int n,s,u,v,w,l[310][310],maxDis,disNode,A,B,pa[310],dist[310],upDis,upNode,I,cnt,flag[310],ldis[310],ans=1e8+7;
//                                                                                ldis两端路径长度（可通过直径减去其算出另外一端）
int ecc,Lcalibre,Rcalibre,lGive,rGive,L,R,mC,ph[310];
int sDis[310],eDis[310],S,E;    // 当点为start || end 时对长度的贡献
bool vis[310];
vector<int> g[310],calibre;
deque <int> q;
void dfs(int fa,int dis) {
    for(vector<int>::iterator it=g[fa].begin();it!=g[fa].end();it++) {
        if(vis[*it]==false && flag[*it]==0) {
            vis[*it]=true,pa[*it]=fa;
            if(dis+l[fa][*it]>maxDis)
                disNode=*it,maxDis=dis+l[fa][*it];
            dfs(*it,dis+l[fa][*it]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n-1;i++) {
        cin>>u>>v>>w;
        l[u][v]=w,l[v][u]=w;
        g[u].push_back(v);g[v].push_back(u);
    }
    vis[1]=true;
    dfs(1,0);
    // 复位以及存储 两遍dfs
    A=disNode;
    fill(&vis[1],&vis[n+1],false);
    maxDis=0,vis[A]=true,pa[A]=A;
    dfs(A,0);
    B=disNode;
    I=B;
    while(true) {
        flag[I]=++cnt;
        ldis[I]=upDis+l[I][upNode];
        upDis=ldis[I],upNode=I;
        calibre.push_back(I);
        if(I==pa[I])
            break;
        I=pa[I];
    }
    mC=ldis[A]; // mC即直径长度
    fill(&vis[1],&vis[n+1],false);
    for(int i=0;i<calibre.size();i++) {
        maxDis=0,vis[calibre[i]]=true;
        dfs(calibre[i],0);
        dist[calibre[i]]=maxDis;
        // cout<<calibre[i]<<" ";
    }
    // cout<<endl;
    // 填充sdis 通过递推
    for(int i=0;i<calibre.size();i++) {
        int ci=calibre[i],ci_1= i+1<calibre.size() ? calibre[i+1]:calibre[i];
        sDis[ci]=max(dist[ci],S);
        S=max(S+l[ci][ci_1],dist[ci]);
    }
    // 填充edis 通过递推
    for(int i=calibre.size()-1;i>=0;i--) {
        int ci=calibre[i],ci_1= i-1>=0 ? calibre[i-1]:calibre[i];
        eDis[ci]=max(dist[ci],E);
        E=max(E+l[ci][ci_1],dist[ci]);
    }
    // 双指针+单调队列(deque实现，因为要从后面出队，里面存的实际上是编号)
    while(L<=R && R<calibre.size()) {
        int cl=calibre[L],cr=calibre[R];
        if(ldis[cr]-ldis[cl]>s) {
            if(q.front()<L+1)   q.pop_front();  // 判断队首元素是否过期
            L++;
            continue;
        }
        while(!q.empty() && dist[cr]>dist[calibre[q.back()]]) {
            q.pop_back();
        }
        q.push_back(R);
        ecc=max(sDis[cl],eDis[cr]);
        ecc=max(ecc,dist[calibre[q.front()]]);
        ans=min(ecc,ans);
        // cout<<L<<" "<<R<<" "<<ans<<" "<<ecc<<endl;
        R++;
    }
    cout<<ans<<endl;
    // debug
    // for(int i=1;i<=n;i++) {
    //     cout<<sDis[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++) {
    //     cout<<eDis[i]<<" ";
    // }
    return 0;
}
// 35pts https://www.luogu.com.cn/record/178185520
// AC https://www.luogu.com.cn/record/178186909 时间复杂度不错，基本都是4ms内解决。