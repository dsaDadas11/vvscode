/*
 * @Author: dsaDadas11
 * @Date: 2025-04-05 11:10:51
 * @LastEditTime: 2025-04-05 11:10:59
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
bool vis[207];
int match[207];
vector<int> g[207];
bool dfs(int u)
{
    for(auto v:g[u])
    {
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v]||dfs(match[v]))
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
void solve()
{
    cin>>n>>m;
    int x,v;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            cin>>v;
            g[i].push_back(v);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) vis[j]=0;
        if(dfs(i)) ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}