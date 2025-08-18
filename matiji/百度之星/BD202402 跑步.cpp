/*
 * @Author: dsaDadas11
 * @Date: 2024-06-04 13:07:46
 * @LastEditTime: 2024-06-04 14:03:45
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+70;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n,cnt;
int a[N],p[N];
void pre()
{
	for(int i=2;i<N;i++)
	{
		if(!a[i]) p[++cnt]=i;
		for(int j=1;j<=cnt&&(ll)p[j]*i<N;j++)
		{
			a[p[j]*i]=1;
			if(!i%p[j]) break;
		}
	}
}
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
int inv[N];
void solve()
{
	cin>>n;
	int L=1;
	for(int i=1;i<=cnt;i++)
	{
		int cur=1;
		while(cur*p[i]<=n)
		{
			cur*=p[i];
		}
		L=(L*cur)%mod;
	}
	inv[1]=1;
	for(int i=2;i<=n;i++)
	{
		inv[i]=mod-(mod/i)*inv[mod%i]%mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(n-2*i+1)*inv[i]%mod;
		ans%=mod;
	}
	ans=(ans*L)%mod;
	cout<<(ans%mod+mod)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; //cin>>T;
	while(T--){solve();}
}


// 另一ac代码：
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+70;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int cnt,n;
int a[N],p[N];
void pre()
{
	for(int i=2;i<N;i++)
	{
		if(!a[i]) p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<N;j++)
		{
			a[p[j]*i]=1;
			if(!i%p[j]) break;
		}
	}
}
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
void solve()
{
	cin>>n;
	int L=1;
	for(int i=1;i<=cnt;i++)
	{
		int cur=1;
		while(cur*p[i]<=n)
		{
			cur*=p[i];
		}
		L=(L*cur)%mod;
	}
	int ans=0,alls=0;
	vector<int> fac(n+1);
	fac[0]=1;
	for(int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	vector<int> rfac(n+2);
	rfac[n+1]=1;
	for(int i=n;i>=1;i--)
	{
		rfac[i]=rfac[i+1]*i%mod;
	}	
	int dL=L*quickpow(fac[n],mod-2)%mod;
	vector<int> iifac(n+1);
	for(int i=1;i<=n;i++)
	{
		iifac[i]=dL*fac[i-1]%mod*rfac[i+1]%mod;
		alls=(alls+iifac[i])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		alls=((alls-iifac[i])%mod+mod)%mod;
		int tot=alls,cnt=n-i;
		ans=(ans+(((iifac[i]*cnt)%mod-tot)%mod+mod)%mod)%mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/