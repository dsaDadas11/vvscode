/*
 * @Author: dsaDadas11
 * @Date: 2025-07-21 16:49:22
 * @LastEditTime: 2025-07-21 16:54:15
 * @Description: go for it!
 */
/*
 点分治模板题
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e4+7;
constexpr int M=1e7+7;
int n,m;
vector<pair<int,int> > g[N]; // v w
int del[N],sz[N],mxs,sum,root; // 求根
int dist[N],d[N],cnt; // 求距离
int ans[N],q[M],judge[M]; // 求路径
int ask[N];
void get_root(int u,int fax)
{
    sz[u]=1;
    int s=0;
    for(auto [v,w]:g[u])
    {
        if(v==fax||del[v]) continue;
        get_root(v,u);
        sz[u]+=sz[v];
        s=max(s,sz[v]);
    }
    s=max(s,sum-sz[u]);
    if(s<mxs) mxs=s,root=u;
}
void get_dist(int u,int fax)
{
    dist[++cnt]=d[u];
    for(auto [v,w]:g[u])
    {
        if(v==fax||del[v]) continue;
        d[v]=d[u]+w;
        get_dist(v,u);
    }
}
void calc(int u)
{
    del[u]=judge[0]=1;
    int p=0;
    // 计算经过根 u的路径
    for(auto [v,w]:g[u])
    {
        if(del[v]) continue;
        // 计算子树 v的各点到 u的距离
        cnt=0;
        d[v]=w;
        get_dist(v,u);
        // 枚举距离和
        for(int i=1;i<=cnt;i++)
        {
            for(int k=1;k<=m;k++)
            {
                if(ask[k]>=dist[i]) ans[k]|=judge[ask[k]-dist[i]];
            }
        }
        // 记录合法距离
        for(int i=1;i<=cnt;i++)
        {
            if(dist[i]<M)
            {
                q[++p]=dist[i];
                judge[dist[i]]=1;
            }
        }
    }
    // 清空 judge
    for(int i=1;i<=p;i++) judge[q[i]]=0;
}
void divide(int u)
{
    // 计算经过根 u的路径
    calc(u);
    // 对 u子树进行分治
    for(auto [v,w]:g[u])
    {
        if(del[v]) continue;
        mxs=sum=sz[v];
        get_root(v,0); // 求根
        divide(root); // 分治
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=m;i++)
    {
        cin>>ask[i];
    }
    mxs=sum=n; // 第一次先找整棵树的重心
    get_root(1,0);
    divide(root);
    for(int i=1;i<=m;i++)
    {
        if(ans[i]) cout<<"AYE"<<endl;
        else cout<<"NAY"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}