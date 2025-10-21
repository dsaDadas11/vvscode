/*
 * @Author: dsaDadas11
 * @Date: 2025-10-14 20:10:13
 * @LastEditTime: 2025-10-14 20:10:23
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int inf=1e16;
int n,a,b;
vector<int> g[N];
int d[N];
vector<int> loop;
void topu()
{
    queue<int> q;
    vector<int> vis(n+1);
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1) q.push(i),vis[i]=1;
    }
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(auto v:g[u])
        {
            d[v]--;
            if(d[v]==1) q.push(v);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        loop.push_back(i);
        // cout<<i<<' ';
    }
}
void dijikstra(int s,vector<int> &dist)
{
    for(int i=1;i<=n;i++) dist[i]=inf;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    vector<int> vis(n+1);
    dist[s]=0;
    pq.push({dist[s],s});
    while(!pq.empty())
    {
        auto [x,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:g[u])
        {
            if(dist[v]>dist[u]+1)
            {
                dist[v]=dist[u]+1;
                pq.push({dist[v],v});
            }
        }
    }
}
void solve()
{
    cin>>n>>a>>b;
    loop.clear();
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        d[i]=0;
    }
    int u,v;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++,d[v]++;
    }

    if(a==b)
    {
        cout<<"NO"<<endl;
        return;
    }

    topu();
    vector<int> dist1(n+1),dist2(n+1);
    dijikstra(a,dist1);
    dijikstra(b,dist2);

    for(auto u:loop)
    {
        if(b==u)
        {
            cout<<"YES"<<endl;
            return;
        }
    }

    for(auto u:loop)
    {
        if(dist1[u]>dist2[u])
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}