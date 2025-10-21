/*
 * @Author: dsaDadas11
 * @Date: 2025-10-16 14:04:01
 * @LastEditTime: 2025-10-16 14:04:40
 * @Description: go for it!
 */
/*
 莫比乌斯反演
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int mod=998244353;
int mu[N],sum[N],f[N],g[N];
int a[N],p[N],cnt,b[N];
void init()
{
    mu[1]=1,g[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i,mu[i]=-1,g[i]=2,b[i]=1;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
        {
            a[p[j]*i]=1;
            if(i%p[j]==0)
            {
                b[i*p[j]]=b[i]+1;
                g[i*p[j]]=g[i]/b[i*p[j]]*(b[i*p[j]]+1);
                break;
            }
            b[p[j]*i]=1;
            g[p[j]*i]=g[i]*2;
            mu[i*p[j]]=-mu[i];
        }
    }

    f[1]=1,f[2]=1;
    for(int i=3;i<N;i++)
    {
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    
    for(int i=1;i<N;i++)
    {
        g[i]%=mod;
        for(int j=i;j<N;j+=i)
        {
            sum[j]+=g[i]*f[i]%mod*mu[j/i]%mod;
            sum[j]%=mod;
        }
    }

    for(int i=1;i<N;i++)
    {
        sum[i]=(sum[i]+mod)%mod;
        sum[i]=(sum[i]+sum[i-1])%mod;
    }
}
int calc(int x)
{
    return x*x%mod*x%mod;
}
int n;
void solve()
{
    cin>>n;
    int ans=0;
    for(int l=1,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        ans+=(sum[r]-sum[l-1])*calc(n/l)%mod;
        ans%=mod;
    }
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}