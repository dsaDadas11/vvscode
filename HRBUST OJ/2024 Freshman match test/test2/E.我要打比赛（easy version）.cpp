/*
 * @Author: dsaDadas11
 * @Date: 2024-11-08 19:25:05
 * @LastEditTime: 2024-11-08 21:59:27
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/U501392
/*
 原codeforces good trip 1900 题改编
 // URL: https://mirror.codeforces.com/problemset/problem/1925/D
 解题思路：
 题目大意是：一共选k支队伍，可以重复选一支队伍，
 当选了一支后，这支队伍的默契值就+1 (但是选的时候还没加)，
 求选k次之后，这些选到队伍的期望(重复的也重复算)。
 这道题就是选k后+1，但是原来的值没有变化，因此就相当于加了k个初始期望，即为k*sum/n
 然后我们单独的看一支队伍，当它在k中取了i次时，就相当于增加了 (0+1+2+...+k-1)的贡献，即i*(i-1)/2
 那么就有期望：
 k
 Σ i*(i-1)/2 * C(k,i) * (1/n)^i * (1-1/n)^(k-i)
 i=0
 因为对于所有的默契值而言都是一样的，因此最后将单独一支队伍的期望乘以n即可
 最后答案：
   k
 n*Σ i*(i-1)/2 * C(k,i) * (1/n)^i * (1-1/n)^(k-i) + k*sum/n
   i=0

   校OJ有点慢，优化后才能过
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
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
		sum%=mod;
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
	ans2=(ans2*n)%mod;
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