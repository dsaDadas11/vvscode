/*
 * @Author: dsaDadas11
 * @Date: 2025-08-14 16:07:49
 * @LastEditTime: 2025-08-14 16:07:59
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
vector<int> g[N];
int dep[N],sz[N];
int dp[N]; // 以 i为根的个节点总深度
void dfs1(int u,int fax)
{
    sz[u]=1;
    dep[u]=dep[fax]+1;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}
void dfs2(int u,int fax)
{
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dp[v]=dp[u]+sz[1]-2*sz[v];
        dfs2(v,u);
    }
}
void solve()
{
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    for(int i=1;i<=n;i++)
    {
        dp[1]+=dep[i]; // 初始化以 1为根跑dfs1的 dp[1]
    }
    dfs2(1,0);
    int ans=0,val=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>val)
        {
            ans=i,val=dp[i];
        }
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