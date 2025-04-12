/*
 * @Author: dsaDadas11
 * @Date: 2025-03-24 19:55:50
 * @LastEditTime: 2025-03-24 19:56:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
vector<int> g[N];
int fa[N],dep[N],dp[N],sum[N];
void solve()
{
    cin>>n;
    for(int i=0;i<=n+3;i++)
    {
        fa[i]=dep[i]=dp[i]=sum[i]=0;
        g[i].clear();
    }

    for(int i=2;i<=n;i++)
    {
        cin>>fa[i];
        dep[i]=dep[fa[i]]+1;
        g[dep[i]].push_back(i);
    }

    sum[0]=1,dp[1]=1;
    for(int i=1;i<n;i++)
    {
        for(auto v:g[i])
        {
            dp[v]+=sum[dep[v]-1];
            if(dep[v]!=1) dp[v]-=dp[fa[v]];
            dp[v]=(dp[v]%mod+mod)%mod;

            sum[dep[v]]+=dp[v];
            sum[dep[v]]%=mod;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+dp[i])%mod;
    }
    cout<<(ans%mod+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}