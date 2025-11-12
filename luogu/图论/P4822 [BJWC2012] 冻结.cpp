/*
 * @Author: dsaDadas11
 * @Date: 2025-10-31 19:19:57
 * @LastEditTime: 2025-10-31 19:20:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
vector<pair<int,int> > g[N];
int dis[N];
bool vis[N];
void dijikstra(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<> > pq;
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    pq.push({dis[s],s});

    while(!pq.empty())
    {
        auto [c,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;

        for(auto [v,w]:g[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        for(int j=1;j<=k;j++)
        {
            g[u+j*n].push_back({v+j*n,w});
            g[v+j*n].push_back({u+j*n,w});
            g[u+(j-1)*n].push_back({v+j*n,w/2});
            g[v+(j-1)*n].push_back({u+j*n,w/2});
        }
    }

    for(int j=1;j<=k;j++)
    {
        g[n+(j-1)*n].push_back({n+j*n,0});
    }

    dijikstra(1);
    cout<<dis[n+k*n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}