/*
 * @Author: dsaDadas11
 * @Date: 2025-05-17 12:43:14
 * @LastEditTime: 2025-05-17 12:43:25
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
int n,k;
int f[N];
int g[1007];
int fac[1007];
void init()
{
    fac[1]=1;
    for(int i=2;i<=1000;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int sum=0;
        for(int j=1;j<i;j++)
        {
            sum+=fac[j]*g[i-j]%mod;
            sum%=mod;
        }
        g[i]=fac[i]-sum;
        g[i]=(g[i]%mod+mod)%mod;
    }

    f[k]=fac[k];
    for(int i=k+1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            f[i]+=f[i-j]*g[j]%mod;
            f[i]%=mod;
        }
    }
    cout<<f[n]%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}