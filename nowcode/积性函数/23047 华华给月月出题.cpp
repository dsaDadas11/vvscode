/*
 * @Author: dsaDadas11
 * @Date: 2025-10-12 22:11:38
 * @LastEditTime: 2025-10-12 22:11:48
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=1.3e7+7;
constexpr int mod=1e9+7;
ll quickpow(ll x,int y)
{
    ll ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
ll m;
bool a[N];
int p[N];
ll f[N]; // f[i]为 i^M
int M;
void init()
{
    f[1]=1; // 特判 1^M
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++m]=i,f[i]=quickpow(i,M);
        for(int j=1;j<=m&&(ll)i*p[j]<N;j++)
        {
            a[p[j]*i]=1;
            if(i%p[j]==0) // i有多个质因子 p[j]
            {
                f[i*p[j]]=f[i]*f[p[j]]%mod;
                break;
            }
            // i只有一个质因子 p[j]
            f[i*p[j]]=f[i]*f[p[j]]%mod;
        }
    }
}
void solve()
{
    cin>>M;
    init();
    ll ans=0;
    for(int i=1;i<=M;i++)
    {
        ans^=f[i];
        // cout<<"f[i]: "<<f[i]<<endl;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}