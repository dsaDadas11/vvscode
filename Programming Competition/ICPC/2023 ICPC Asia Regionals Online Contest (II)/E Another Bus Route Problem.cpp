/*
 * @Author: dsaDadas11
 * @Date: 2025-09-11 21:10:12
 * @LastEditTime: 2025-09-11 21:10:19
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int p[N],dist[N];
vector<int> g[N];
void solve()
{
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        dist[i]=-1;
    }

    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            while(dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
                v=p[v];
            }
        }
    }
    
    for(int i=2;i<=n;i++) cout<<dist[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}