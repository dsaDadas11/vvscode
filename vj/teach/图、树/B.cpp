/*
 * @Author: dsaDadas11
 * @Date: 2025-10-27 16:21:33
 * @LastEditTime: 2025-10-27 16:26:52
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m;
vector<int> g[N];
int ans[N];
void dfs(int u,int tar)
{
    if(ans[u]) return;
    ans[u]=tar;

    for(auto v:g[u])
    {
        if(ans[v]) continue;
        dfs(v,tar);
    }
}
void solve()
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        // g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=n;i>=1;i--)
    {
        if(ans[i]) continue;
        dfs(i,i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}