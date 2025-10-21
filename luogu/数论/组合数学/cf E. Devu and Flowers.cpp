/*
 * @Author: dsaDadas11
 * @Date: 2025-09-16 19:07:00
 * @LastEditTime: 2025-09-16 19:07:26
 * @Description: go for it!
 */
// URL：https://codeforces.com/contest/451/problem/E
/*
 tag: 多重集组合数 + 容斥
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n,s;
int f[27];
int fac[27],inv[27];
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
void init()
{
    fac[0]=1;
    for(int i=1;i<=20;i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
    inv[20]=quickpow(fac[20],mod-2);
    for(int i=19;i>=0;i--)
    {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
int C(int n,int m)
{
    if(n<m) return 0;
    int ans=1;
    for(int i=n;i>=n-m+1;i--)
    {
        ans=ans*(i%mod)%mod;
    }
    ans=ans*inv[m]%mod;
    return ans;
}
void solve()
{
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>f[i];
    int ans=C(n+s-1,n-1);

    for(int i=1;i<(1<<n);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1) sum+=f[j]+1;
        }
        int cnt=__builtin_popcount(i);
        if(cnt&1) ans-=C(n+s-1-sum,n-1);
        else ans+=C(n+s-1-sum,n-1);
        ans%=mod;
    }
    cout<<(ans+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}