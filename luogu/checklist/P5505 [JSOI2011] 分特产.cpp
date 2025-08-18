/*
 * @Author: dsaDadas11
 * @Date: 2025-07-24 18:37:24
 * @LastEditTime: 2025-07-24 18:43:37
 * @Description: go for it!
 */
/*
 解题思路：
 这道题用到了组合数和容斥原理
 首先我们求至少 i个盒子为空的方案数 f[i]，我们可以先固定 i个人，方案数为 C(n,i)
 然后我们采用隔板法将 n-i-1个人分 a[j]个物品的方案数(隔板可能为空)为 C(a[j]+n-i-1,n-i-1)
 有 m个物品，连乘得 Π(j=1,m) C(a[j]+n-i-1,n-i-1)
 那么 f[i] = C(n,i) * Π[j=1,m] C(a[j]+n-i-1,n-i-1)
 我们可以观察到 f[i]肯定包含 f[i+1]的情况，因此需要用容斥
 ans = ∑[0,n-1] (-1)^i * f[i] (没有n的情况)
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
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
int n,m;
int a[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int res=C(n,i);
        for(int j=1;j<=m;j++)
        {
            res*=C(a[j]+n-i-1,n-i-1);
            res%=mod;
        }
        if(i&1) ans-=res;
        else ans+=res;
        ans=(ans%mod+mod)%mod;
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