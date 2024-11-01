/*
 * @Author: dsaDadas11
 * @Date: 2024-09-17 16:40:36
 * @LastEditTime: 2024-09-17 16:40:46
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,ans;
int val[M][M];
int dp[M][M];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>val[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=max({dp[i][j],dp[i-1][j-1]+val[i][j],dp[i-1][j]+val[i][j]});
		}
	}
	for(int j=1;j<=n;j++)
	{
		ans=max(ans,dp[n][j]);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}