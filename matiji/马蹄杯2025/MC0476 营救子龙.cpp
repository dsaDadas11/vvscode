/*
 * @Author: dsaDadas11
 * @Date: 2025-08-23 15:50:05
 * @LastEditTime: 2025-08-23 15:50:42
 * @Description: go for it!
 */
/*
 单独算一个数的贡献就可以了。。。
 快速幂会超时
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n,m;
int a[N];
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
int p[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    p[0]=1;
    for(int i=1;i<=m;i++)
    {
        p[i]=p[i-1]*(n-1)%mod;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            ans+=__builtin_popcount(a[i]+j)*C(m,j)%mod*p[m-j];
            ans%=mod;
        }
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