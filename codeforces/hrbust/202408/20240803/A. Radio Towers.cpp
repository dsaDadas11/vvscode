/*
 * @Author: dsaDadas11
 * @Date: 2024-08-03 14:56:32
 * @LastEditTime: 2024-08-03 14:57:17
 * @Description: go for it!
 */
/*
 不会dp写法，写成dfs段错误，只能写斐波那契数列了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
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
int dp[N];
int n;
void solve()
{
	dp[0]=1,dp[1]=1,dp[2]=1;
	cin>>n;
	int fmu=quickpow(2,n);
	for(int i=3;i<=n;i++)
	{
		dp[i]+=(dp[i-1]+dp[i-2])%mod;
		dp[i]%=mod;
	}
	cout<<dp[n]*niyuan(fmu)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}