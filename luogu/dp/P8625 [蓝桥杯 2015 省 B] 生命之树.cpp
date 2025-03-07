/*
 * @Author: dsaDadas11
 * @Date: 2025-03-03 21:05:11
 * @LastEditTime: 2025-03-04 18:07:20
 * @Description: go for it!
 */
/*
 解题思路:
 树形dp，可以观察到每颗子树只有选或不选两种情况，那么就可以定义dp[i][0],dp[i][1]
 其实可以不用
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
int dp[N][2];
vector<int> g[N];
void dfs(int u,int fax)
{
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
        dp[u][1]+=max(dp[v][1],dp[v][0]);
    }
    dp[u][1]+=a[u];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]);
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