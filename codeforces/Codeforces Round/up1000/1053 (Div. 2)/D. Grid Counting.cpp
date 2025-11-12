/*
 * @Author: dsaDadas11
 * @Date: 2025-11-03 16:19:22
 * @LastEditTime: 2025-11-03 16:19:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int mod=998244353;
int f[N],g[N];
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
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%mod;
    }

    g[N-1]=quickpow(f[N-1],mod-2);
    for(int i=N-1;i>=1;i--)
    {
        g[i-1]=g[i]*i%mod;
    }
}
int C(int n,int m)
{
    if(n<m||n<0||m<0) return 0;
    return f[n]*g[m]%mod*g[n-m]%mod;
}
int n;
int a[N],res[N];
void solve()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum!=n)
    {
        cout<<0<<endl;
        return;
    }

    int len=(n+1)/2;
    for(int i=len+1;i<=n;i++)
    {
        if(a[i]!=0)
        {
            cout<<0<<endl;
            return;
        }
    }

    if(n%2) res[len]=1;
    else res[len]=2;

    for(int i=len-1;i>=1;i--)
    {
        res[i]=res[i+1]+2;
    }

    int ans=1;
    sum=0;
    for(int i=len;i>=1;i--)
    {
        ans=ans*C(res[i]-sum,a[i])%mod;
        sum+=a[i];
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