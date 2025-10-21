/*
 * @Author: dsaDadas11
 * @Date: 2025-09-15 11:57:41
 * @LastEditTime: 2025-09-15 11:58:38
 * @Description: go for it!
 */
/*
 t = 2^m
 f(n) = t*(t-1)^(n-2) - f(n-2)*(t-1)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n,m;
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
void solve()
{
    cin>>n>>m;
    if(n==1)
    {
        cout<<1<<endl;
        return; 
    }
    if(n==2)
    {
        cout<<0<<endl;
        return;
    }

    int t=quickpow(2,m);

    if(n&1)
    {
        cout<<quickpow(t-1,n-1)<<endl;
    }
    else
    {
        int sign=((n/2)&1)?-1:1;
        cout<<((quickpow(t-1,n-1)+sign*quickpow(t-1,n/2))%mod+mod)%mod<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}