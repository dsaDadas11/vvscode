/*
 * @Author: dsaDadas11
 * @Date: 2025-04-10 20:33:00
 * @LastEditTime: 2025-04-10 20:36:51
 * @Description: go for it!
 */
/*
 解题思路：
 这道题可以拿 dp模拟最短路做，状态转移方程和最短路一样
 也可以直接建图跑 dijkstra
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=4e3+7;
int dp[M];
void solve()
{
    memset(dp,0x3f,sizeof dp);
    dp[1]=0;
    for(int i=1;i<=2021;i++)
    {
        for(int j=i+1;j<=i+21;j++)
        {
            if(j>2021) break;
            int lc=lcm(i,j);
            dp[j]=min(dp[j],dp[i]+lc);
        }
    }
    cout<<dp[2021];
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=4e3+7;
struct Edge
{
    int v,w;
};
vector<Edge> g[M];
int dist[M];
int vis[M];
void dijkstra(int n,int s)
{
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;
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
    for(int i=1;i<=2021;i++)
    {
        for(int j=i+1;j<=i+21;j++)
        {
            if(j>2021) break;
            int lc=lcm(i,j);
            g[i].push_back({j,lc});
            g[j].push_back({i,lc});
        }
    }
    dijkstra(2021,1);
    cout<<dist[2021];
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/