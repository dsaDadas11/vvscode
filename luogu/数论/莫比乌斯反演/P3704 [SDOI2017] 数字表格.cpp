/*
 * @Author: dsaDadas11
 * @Date: 2025-10-15 20:42:17
 * @LastEditTime: 2025-10-15 20:42:25
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int mod=1e9+7;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int ni(int x)
{
    return quickpow(x,mod-2);
}
int mu[N],f[N],g[N]; // 正  逆
int F[N]; // f[]^mu[] 的前缀积
int a[N],p[N],cnt;
void init()
{
    mu[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
        {
            a[i*p[j]]=1;
            if(i%p[j]==0) break;
            mu[i*p[j]]=-mu[i];
        }
    }

    f[1]=1,g[1]=1,F[0]=F[1]=1;
    for(int i=2;i<N;i++)
    {
        f[i]=(f[i-1]+f[i-2])%mod;
        g[i]=ni(f[i]);
        F[i]=1;
    }

    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            if(mu[j/i]==0) continue;
            F[j]*=(mu[j/i]==1?f[i]:g[i]);
            F[j]%=mod;
        }
    }

    for(int i=1;i<N;i++)
    {
        F[i]=F[i]*F[i-1]%mod;
    }
}
int n,m;
void solve()
{
    cin>>n>>m;
    if(n>m) swap(n,m);
    int ans=1;
    for(int l=1,r;l<=n;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));
        ans*=quickpow(F[r]*ni(F[l-1])%mod,(n/l)*(m/l));
        ans%=mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}