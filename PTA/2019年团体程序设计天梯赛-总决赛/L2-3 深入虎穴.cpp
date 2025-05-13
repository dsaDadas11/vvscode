/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 21:21:33
 * @LastEditTime: 2025-04-15 21:25:01
 * @Description: go for it!
 */
/*
 解题思路：
 最短路板子题
 但是题目并没说起点在哪，
 看了题解后理解了起点一个性质：没有边与起点相连，可以据此找到起点
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define pll pair<int,int>
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
vector<pll> g[N];
int dist[N];
bool vis[N];
void dijkstra(int s)
{
    priority_queue<pll,vector<pll>,greater<> > pq;
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [w,v]:g[u])
        {
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
bool isl[N];
void solve()
{
    cin>>n;
    int k,v;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>v;
            isl[v]=1;
            g[i].push_back({1,v});
        }
    }
    int st=1;
    for(int i=1;i<=n;i++)
    {
        if(!isl[i])
        {
            st=i;
            break;
        }
    }
    int mx=0;
    dijkstra(st);
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,dist[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==mx)
        {
            cout<<i<<endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}