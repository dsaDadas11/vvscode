/*
 * @Author: dsaDadas11
 * @Date: 2025-10-15 19:57:44
 * @LastEditTime: 2025-10-15 19:57:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+5;
constexpr int mod=20101009;
int mu[N],sum[N];
int a[N],p[N],cnt;
void init()
{
    mu[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
        {
            a[p[j]*i]=1;
            if(i%p[j]==0) break;
            mu[p[j]*i]=-mu[i];
        }
    }

    for(int i=1;i<N;i++)
    {
        sum[i]=sum[i-1]+mu[i]*i*i%mod;
        sum[i]%=mod;
    }
}
int g(int n,int m)
{
    int ans1=n*(n+1)/2;
    ans1%=mod;
    int ans2=m*(m+1)/2;
    ans2%=mod;

    return ans1*ans2%mod;
}
int f(int n,int m)
{
    int ans=0;
    for(int l=1,r;l<=n;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));
        ans+=(sum[r]-sum[l-1])*g(n/l,m/l)%mod;
        ans%=mod;
    }
    ans=(ans%mod+mod)%mod;
    return ans;
}
int n,m;
void solve()
{
    cin>>n>>m;
    if(n>m) swap(n,m);
    int ans=0;
    for(int l=1,r;l<=n;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));
        ans+=((r-l+1)*(r+l)/2)%mod*f(n/l,m/l)%mod;
        ans%=mod;
    }
    ans=(ans%mod+mod)%mod;
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