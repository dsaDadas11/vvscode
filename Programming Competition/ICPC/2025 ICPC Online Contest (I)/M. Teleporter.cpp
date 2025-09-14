/*
 * @Author: dsaDadas11
 * @Date: 2025-09-09 13:34:36
 * @LastEditTime: 2025-09-09 13:34:46
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define pll pair<int,int>
using namespace std;
constexpr int N=5e3+7;
constexpr int M=2e3+7;
constexpr int inf=1e16;
int n,m,k;
vector<pll> g1[N];
vector<int> g2[N];
int f[N][N]; // u节点传送 k次的最小贡献
void dfs(int u,int fax)
{
    for(auto [v,w]:g1[u])
    {
        if(v==fax) continue;
        f[v][0]=f[u][0]+w;
        dfs(v,u);
    }
}
void solve()
{
    cin>>n>>m;
    k=n;
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        g1[u].push_back({v,w});
        g1[v].push_back({u,w});
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        g2[i].push_back(i);
    }
    dfs(1,0);
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=n;i++) f[i][j]=inf;
        
        for(int u=1;u<=n;u++)
        {
            for(auto v:g2[u])
            {
                f[u][j]=min(f[u][j],f[v][j-1]);
            }
        }

        vector<int> vis(n+1);
        priority_queue<pll,vector<pll>,greater<pll> > pq;
        for(int i=1;i<=n;i++)
        {
            if(f[i][j]!=inf) pq.push({f[i][j],i});
        }
        while(!pq.empty())
        {
            auto [tmp,u]=pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto [v,w]:g1[u])
            {
                if(f[v][j]>f[u][j]+w)
                {
                    f[v][j]=f[u][j]+w;
                    pq.push({f[v][j],v});
                }
            }
        }
    }

    for(int j=0;j<=k;j++)
    {
        int ans=0;
        for(int i=1;i<=n;i++) ans+=f[i][j];
        cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}