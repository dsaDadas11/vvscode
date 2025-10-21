/*
 * @Author: dsaDadas11
 * @Date: 2025-10-10 22:35:49
 * @LastEditTime: 2025-10-10 22:35:56
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
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
int f[N],g[N];
void init()
{
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%mod;
    }
    g[N-1]=ni(f[N-1]);
    for(int i=N-1;i>=1;i--)
    {
        g[i-1]=g[i]*i%mod;
    }
}
int C(int n,int m)
{
    if(m>n||n<0||m<0) return 0;
    return f[n]*g[m]%mod*g[n-m]%mod;
}
int a,b,k;
void solve()
{
    cin>>a>>b>>k;
    int n=k*(a-1)+1;
    int m=k*g[a]%mod*(b-1)%mod;
    for(int i=n;i>=n-a+1;i--)
    {
        m=(m*(i%mod))%mod;
    }
    m=(m+1)%mod;
    n%=mod;
    cout<<n<<' '<<m<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}