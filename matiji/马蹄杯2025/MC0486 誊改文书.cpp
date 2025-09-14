/*
 * @Author: dsaDadas11
 * @Date: 2025-09-01 09:40:50
 * @LastEditTime: 2025-09-01 09:41:01
 * @Description: go for it!
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
string s;
int f[N],g[N]; //阶乘 阶乘逆元
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
int niyuan(int x)
{
	return quickpow(x,mod-2);
}
int C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return (((f[n]*g[m])%mod)*g[n-m])%mod;
}
void init()
{
	f[0]=1;
	for(int i=1;i<N;i++)
	{
		f[i]=(f[i-1]*i)%mod;
	}
	g[N-1]=niyuan(f[N-1]);
	for(int i=N-1;i>=1;i--)
	{
		g[i-1]=(g[i]*i)%mod;
	}
}
int sum[N];
void solve()
{
    cin>>n>>m;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A') a++;
        if(s[i]=='B') b++;
    }

    sum[0]=C(b,0);
    for(int i=1;i<=min(b,m);i++)
    {
        sum[i]=sum[i-1]+C(b,i);
        sum[i]%=mod;
    }

    int ans=0;
    int p=1;
    for(int i=0;i<=m;i++)
    {
        int t=min(m-i,b);
        ans+=C(a,i)*p%mod*sum[t]%mod;
        ans%=mod;
        p=p*2%mod;
    }
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