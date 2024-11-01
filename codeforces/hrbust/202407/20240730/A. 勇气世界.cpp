/*
 * @Author: dsaDadas11
 * @Date: 2024-07-30 18:47:34
 * @LastEditTime: 2024-07-30 18:49:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int cost[M],w[M];
int dp[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>cost[i]>>w[i];
	fill(dp,dp+1+N,1e18);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(w[i]>=m) continue;
		for(int j=w[i];j<=m*5;j++)
		{
			dp[j]=min(dp[j],dp[j-w[i]]+cost[i]);
		}
	}
	int ans=1e18;
	for(int i=m;i<=5*m;i++)
	{
		ans=min(ans,dp[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(w[i]>=m)
		{
			ans=min(ans,cost[i]);
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 更简便的ac代码，主要是将多余w的钱换成w的操作：
 dp[j]=min(dp[j],dp[max(0LL,j-w[i])]+cost[i]);

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int cost[M],w[M];
int dp[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>cost[i]>>w[i];
	fill(dp,dp+1+m,1e18);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			dp[j]=min(dp[j],dp[max(0LL,j-w[i])]+cost[i]);
		}
	}
	cout<<dp[m]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/