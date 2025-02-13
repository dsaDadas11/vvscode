/*
 * @Author: dsaDadas11
 * @Date: 2024-12-05 23:48:59
 * @LastEditTime: 2024-12-06 22:44:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
constexpr int inf=1e18;
string a,b,c;
int dp[M][M];
void solve()
{
	cin>>a>>b>>c;
	int n=a.size(),m=b.size();
	a=' '+a,b=' '+b,c=' '+c;
	for(int i=0;i<=n+5;i++)
	{
		for(int j=0;j<=m+5;j++)
		{
			dp[i][j]=inf;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j>0)
			if(b[j]==c[i+j]) dp[i][j]=min(dp[i][j],dp[i][j-1]);
			else dp[i][j]=min(dp[i][j],dp[i][j-1]+1);

			if(i>0)
			if(a[i]==c[i+j]) dp[i][j]=min(dp[i][j],dp[i-1][j]);
			else dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
		}
	}
	cout<<dp[n][m]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}