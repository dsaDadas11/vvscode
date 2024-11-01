/*
 * @Author: dsaDadas11
 * @Date: 2024-07-25 20:38:51
 * @LastEditTime: 2024-07-25 20:39:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
ll dp[N][3]; // 第i个位置 被3除余几
int n,l,r;
int zero,one,two;
void solve()
{
	cin>>n>>l>>r;
	zero=r/3-(l-1)/3;
	one=(r+1)/3-l/3;
	two=(r+2)/3-(l+1)/3;
	dp[1][0]=zero;
	dp[1][1]=one;
	dp[1][2]=two;
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=((1LL*dp[i-1][0]*zero)%mod+(1LL*dp[i-1][1]*two)%mod+(1LL*dp[i-1][2]*one)%mod+mod)%mod;
		dp[i][1]=((1LL*dp[i-1][0]*one)%mod+(1LL*dp[i-1][1]*zero)%mod+(1LL*dp[i-1][2]*two)%mod+mod)%mod;
		dp[i][2]=((1LL*dp[i-1][0]*two)%mod+(1LL*dp[i-1][1]*one)%mod+(1LL*dp[i-1][2]*zero)%mod+mod)%mod;
	}
	cout<<dp[n][0]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}