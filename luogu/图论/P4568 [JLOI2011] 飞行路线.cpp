/*
 * @Author: dsaDadas11
 * @Date: 2025-10-31 19:05:24
 * @LastEditTime: 2025-10-31 19:05:33
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k,s,t;
vector<pair<int,int> > g[N];
int dist[N];
bool vis[N];
void dijikstra(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    pq.push({dist[s],s});

    while(!pq.empty())
    {
        auto [c,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;

        for(auto [v,w]:g[u])
        {
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>k;
    cin>>s>>t;
    s++,t++;

    int u,v,c;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>c;
        u++,v++;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
        for(int j=1;j<=k;j++)
        {
            // 每层的连边
            g[u+j*n].push_back({v+j*n,c});
            g[v+j*n].push_back({u+j*n,c});
            // 层与层之间的连边，这里的权值由题意而定
            g[u+(j-1)*n].push_back({v+j*n,0});
            g[v+(j-1)*n].push_back({u+j*n,0});
        }
    }

    // 将每一层的终点连接起来（因为不一定必须经过 k次才到终点）
    for(int j=1;j<=k;j++)
    {
        g[t+(j-1)*n].push_back({t+j*n,0});
    }

    dijikstra(s);
    cout<<dist[t+k*n]<<endl; // 最终答案存在最后一层
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}