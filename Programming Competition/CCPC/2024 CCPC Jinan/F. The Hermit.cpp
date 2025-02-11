/*
 * @Author: dsaDadas11
 * @Date: 2025-01-15 16:03:43
 * @LastEditTime: 2025-01-15 16:17:55
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
    if(m>n||m<0) return 0;
	return (((f[n]*g[m])%mod)*g[n-m])%mod;
}
void init()
{
	f[0]=1;
	for(int i=1;i<=2e5;i++)
	{
		f[i]=(f[i-1]*i)%mod;
	}
	g[200000]=niyuan(f[200000]);
	for(int i=200000;i>=1;i--)
	{
		g[i-1]=(g[i]*i)%mod;
	}
}
int n,m;
void solve()
{
    cin>>m>>n;
    int ans=n*C(m,n)%mod;
    unordered_map<int,unordered_map<int,int> > f; // 长度为 i 且当前数为 x的链
    for(int i=1;i<=m;i++) f[1][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(auto [x,y]:f[i])
        {
            if(m/x-1>=n-i) ans-=f[i][x]*C(m/x-1,n-i)%mod;
            ans=(ans%mod+mod)%mod;
            for(int j=2;j*x<=m&&i+1<=n;j++)
            {
                f[i+1][j*x]=(f[i+1][j*x]+f[i][x])%mod;
            }
        }
    }
    cout<<(ans%mod+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

/*
另一份ac代码

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
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
    if(m>n||m<0) return 0;
	return (((f[n]*g[m])%mod)*g[n-m])%mod;
}
void init()
{
	f[0]=1;
	for(int i=1;i<=2e5;i++)
	{
		f[i]=(f[i-1]*i)%mod;
	}
	g[200000]=niyuan(f[200000]);
	for(int i=200000;i>=1;i--)
	{
		g[i-1]=(g[i]*i)%mod;
	}
}
int n,m;
int dp[N][25];
void solve()
{
    cin>>m>>n;
    int ans=n*C(m,n)%mod;
    for(int i=1;i<=m;i++)
    {
        dp[i][1]++;
        for(int k=1;k<=20;k++)
        {
            if(dp[i][k]==0) continue;
            ans-=dp[i][k]*C(m/i-1,n-k)%mod;
            ans%=mod;
        }
        for(int j=i*2;j<=m;j+=i)
        {
            for(int k=1;k<=20;k++)
            {
                dp[j][k+1]=(dp[j][k+1]+dp[i][k])%mod;
            }
        }
    }
    cout<<(ans%mod+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

*/