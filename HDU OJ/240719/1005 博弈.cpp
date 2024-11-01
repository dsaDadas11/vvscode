/*
 * @Author: dsaDadas11
 * @Date: 2024-07-22 11:05:40
 * @LastEditTime: 2024-07-22 11:06:11
 * @Description: go for it!
 */
/*
 组合数怎么算的？？？
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
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
	return (((f[n]*g[m])%mod)*g[n-m])%mod;
}
void pre()
{
	f[0]=1;
	for(int i=1;i<=1e7;i++)
	{
		f[i]=(f[i-1]*i)%mod;
	}
	g[10000000]=niyuan(f[10000000]);
	for(int i=10000000;i>=1;i--)
	{
		g[i-1]=(g[i]*i)%mod;
	}
}
int n;
char c[107];
unordered_map<char,int> mp;
void solve()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		cin>>mp[c[i]];
		sum+=mp[c[i]];
	}
	if(sum%2) //奇数
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(mp[c[i]]%2) cnt++;
		}
		if(cnt==1)
		{
			int p=g[sum];
			for(int i=1;i<=n;i++)
			{
				p=(p*f[mp[c[i]]])%mod;
			}
			p=(p*f[sum/2])%mod;
			for(int i=1;i<=n;i++)
			{
				p=(p*g[mp[c[i]]/2])%mod;
			}
			cout<<(1+p)*g[2]%mod<<endl;
		}
		else cout<<g[2]<<endl;
	}
	else // 偶数
	{
		int p=g[sum];
		for(int i=1;i<=n;i++)
		{
			p=(p*f[mp[c[i]]])%mod;
		}
		p=(p*f[sum/2])%mod;
		for(int i=1;i<=n;i++)
		{
			if(mp[c[i]]%2) p=0;
			else p=(p*g[mp[c[i]]/2])%mod;
		}
		cout<<(1-p+mod)*g[2]%mod<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}