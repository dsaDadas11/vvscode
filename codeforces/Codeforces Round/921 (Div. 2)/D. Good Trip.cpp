/*
 * @Author: dsaDadas11
 * @Date: 2025-01-23 19:51:28
 * @LastEditTime: 2025-01-23 19:54:38
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n,m,k;
int f[N],g[N];
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int niyuan(int x)
{
	return quickpow(x,mod-2);
}
int C(int n,int m)
{
	if(m>n||m<0) return 0;
	return (((f[n]*g[m])%mod)*g[n-m])%mod;
}
void init()
{
	f[0]=1;
	for(int i=1;i<N;i++)
	{
		f[i]=f[i-1]*i%mod;
	}
	g[200000]=niyuan(f[200000]);
	for(int i=200000;i>=1;i--)
	{
		g[i-1]=g[i]*i%mod;
	}
}
void solve()
{
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,x;
		cin>>a>>b>>x;
		sum=(sum+x)%mod;
	}
	int p=niyuan(C(n,2));
	int resp=((1LL-p)%mod+mod)%mod;
	int ans=(k*sum%mod)*p%mod;
	int ni2=niyuan(2);
	int res=0;
	for(int i=2;i<=k;i++)
	{
		int tmp=(i*(i-1)%mod)*ni2%mod;
		res+=((quickpow(p,i)*tmp%mod)*C(k,i)%mod)*quickpow(resp,k-i)%mod;
		res%=mod;
	}
	cout<<((ans+m*res%mod)%mod+mod)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}