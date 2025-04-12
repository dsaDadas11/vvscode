/*
 * @Author: dsaDadas11
 * @Date: 2025-04-06 19:13:01
 * @LastEditTime: 2025-04-06 19:13:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int r[N];
int dp[N][2];
vector<int> g[N];
void dfs(int u)
{
    dp[u][1]=r[u];
    for(auto v:g[u])
    {
        dfs(v);
        dp[u][0]+=max(dp[v][1],dp[v][0]);
        dp[u][1]+=dp[v][0];
    }
}
int fa[N];
int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        fa[i]=i;
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>v>>u;
        g[u].push_back(v);
        fa[v]=u;
    }
    int fax=find_fa(1);
    dfs(fax);
    cout<<max(dp[fax][0],dp[fax][1])<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}