/*
 * @Author: dsaDadas11
 * @Date: 2025-04-13 22:38:22
 * @LastEditTime: 2025-04-14 12:34:04
 * @Description: go for it!
 */
/*
 解题思路：
 最短路计数,题目要求只能建单向边
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define pll pair<int,int>
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e16;
int n,m,s,t;
void dijkstra(int s,vector<int>& dist,vector<int>& cnt,vector<vector<pll>>& g)
{
    priority_queue<pll,vector<pll>,greater<> > pq;
    dist[s]=0,cnt[s]=1;
    pq.push({0,s});
    vector<bool> vis(n+5);
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [w,v]:g[u])
        {
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                cnt[v]=cnt[u];
                pq.push({dist[v],v});
            }
            else if(dist[v]==dist[u]+w) cnt[v]+=cnt[u];
        }
    }
}
tuple<int,int,int> p[N];
void solve()
{
    cin>>n>>m>>s>>t;
    int u,v,w;
    vector<vector<pll> > g1(n+5),g2(n+5);
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        p[i]={u,v,w};
        g1[u].push_back({w,v});
        g2[v].push_back({w,u});
    }
    vector<int> cnts(n+5),cntt(n+5);
    vector<int> ds(n+5,inf),dt(n+5,inf);
    dijkstra(s,ds,cnts,g1);
    dijkstra(t,dt,cntt,g2);
    
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        auto [u,v,w]=p[i];
        if(ds[u]+w+dt[v]==ds[t]&&cnts[u]*cntt[v]==cnts[t]) ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}