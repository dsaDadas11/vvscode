/*
 * @Author: dsaDadas11
 * @Date: 2025-08-14 16:56:32
 * @LastEditTime: 2025-08-14 16:57:52
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
int c[N];
vector<pair<int,int> > g[N]; // v w
int sz[N];
int dp[N];
int sum[N];
void dfs1(int u,int fax)
{
    sz[u]=c[u];
    for(auto [v,w]:g[u])
    {
        if(v==fax) continue;
        dfs1(v,u);
        sum[u]+=sum[v]+sz[v]*w;
        sz[u]+=sz[v];
    }
}
void dfs2(int u,int fax)
{
    for(auto [v,w]:g[u])
    {
        if(v==fax) continue;
        dp[v]=dp[u]+(sz[1]-2*sz[v])*w;
        dfs2(v,u);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    int a,b,l;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b>>l;
        g[a].push_back({b,l});
        g[b].push_back({a,l});
    }
    dfs1(1,0);
    dp[1]=sum[1];
    dfs2(1,0);
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dp[i]);
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