/*
 * @Author: dsaDadas11
 * @Date: 2025-10-17 20:44:05
 * @LastEditTime: 2025-10-17 20:44:24
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e6+7;
constexpr int mod=998244353;
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
int f[N],g[N];
void init()
{
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%mod;
    }
    g[N-1]=quickpow(f[N-1],mod-2);
    for(int i=N-2;i>=0;i--)
    {
        g[i]=g[i+1]*(i+1)%mod;
    }
}
int C(int n,int m)
{
    if(n<0||m<0||n<m) return 0;
    return f[n]*g[m]%mod*g[n-m]%mod;
}
int n,m;
int ans=0;
void solve()
{
    cin>>n>>m;
    ans^=C(n,m);
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T>>n;
    while(T--){solve();}
    cout<<ans<<endl;
    return 0;
}