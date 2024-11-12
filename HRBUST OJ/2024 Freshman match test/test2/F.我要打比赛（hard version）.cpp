/*
 * @Author: dsaDadas11
 * @Date: 2024-11-08 19:32:29
 * @LastEditTime: 2024-11-08 21:58:21
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/U501413
/*
 解题思路：
 详细的见test，虽然说这是hard version,但是easy version会了，这个也会了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int f[N],g[N];
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
	return (((f[n]*g[m])%mod)*g[n-m])%mod;
}
void init()
{
	f[0]=1;
	for(int i=1;i<=1e6;i++)
	{
		f[i]=(f[i-1]*i)%mod;
	}
	g[1000000]=niyuan(f[1000000]);
	for(int i=1000000;i>=1;i--)
	{
		g[i-1]=(g[i]*i)%mod;
	}
}
void solve()
{
	int n,k;
	cin>>n>>k;
	int sum=0,x;
	int m=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
		sum%=mod;
		if(x>0) m++;
	}
	int nin=niyuan(n);
	int ni2=niyuan(2);
	int ans1=(sum*k%mod)*nin%mod;
	int ans2=0;
	int t,p,nip;
	for(int i=1;i<=k;i++)
	{
		t=(i*(i-1)%mod)*ni2%mod;
		p=niyuan(quickpow(n,i));
		nip=quickpow((n-1)*nin%mod,k-i);
		ans2+=((t*C(k,i)%mod)*p%mod)*nip%mod;
		ans2%=mod;
	}
	ans2=(ans2*m)%mod;
	cout<<(ans1+ans2)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}