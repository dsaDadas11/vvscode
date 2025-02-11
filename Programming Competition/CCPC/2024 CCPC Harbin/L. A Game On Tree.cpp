/*
 * @Author: dsaDadas11
 * @Date: 2025-01-13 23:05:22
 * @LastEditTime: 2025-01-13 23:05:33
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
vector<int> g[N];
int s[N],t[N];
int ans;
void dfs(int u,int fa)
{
    s[u]=1;
    int tmp=0,tmp2=0;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        s[u]+=s[v];
        t[u]=(t[u]+t[v])%mod;
        ans+=2LL*(n-s[v])*(n-s[v])%mod*((t[v]-s[v]*s[v]%mod+mod)%mod);
        ans=(ans%mod+mod)%mod;
        tmp=(tmp+t[v])%mod;
        tmp2=(tmp2+t[v]*t[v]%mod)%mod;
    }
    t[u]=(t[u]+s[u]*s[u]%mod)%mod;
    ans+=(s[u]*s[u]%mod*(n-s[u])*(n-s[u])%mod);
    ans=(ans%mod+mod)%mod;
    ans=(ans+((tmp*tmp%mod-tmp2)%mod+mod)%mod)%mod;
}
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=(ans*x)%mod;
        y>>=1;
        x=x*x%mod;
    }
    return ans;
}
int ni(int x)
{
    return quickpow(x,mod-2);
}
void solve()
{
    cin>>n;
    ans=0;
    for(int i=0;i<=n+5;i++)
    {
        g[i].clear();
        s[i]=t[i]=0;
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    ans=(ans*4)%mod;
    int tmp=(n*n%mod)*((n-1)*(n-1)%mod)%mod;
    ans=ans*ni(tmp)%mod;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}