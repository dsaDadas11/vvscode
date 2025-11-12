/*
 * @Author: dsaDadas11
 * @Date: 2025-10-27 11:38:43
 * @LastEditTime: 2025-10-27 11:38:52
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
vector<int> g[N];
int vis1[N],vis2[N];
void dfs(int u)
{
    if(vis1[u]) return;
    vis1[u]=1;
    cout<<u<<' ';
    sort(g[u].begin(),g[u].end());
    for(auto v:g[u])
    {
        if(vis1[v]) continue;
        dfs(v);
    }
}
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis2[u]) continue;
        vis2[u]=1;
        cout<<u<<' ';
        for(auto v:g[u])
        {
            if(vis2[v]) continue;
            q.push(v);
        }
    }
}
void solve()
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }

    dfs(1);
    cout<<endl;
    bfs(1);
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}