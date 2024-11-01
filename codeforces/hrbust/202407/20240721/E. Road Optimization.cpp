/*
 * @Author: dsaDadas11
 * @Date: 2024-07-21 19:46:55
 * @LastEditTime: 2024-07-21 19:47:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,l,k;
int d[507],a[507];
int dp[507][2][507]; // i到i+1 是否移除 移除标志的数量
void solve()
{
	cin>>n>>l>>k;
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	d[n+1]=l;
	//第一个路标不能移除，所以是初状态
	dp[1][0][0]=(d[2]-d[1])*a[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			// 不移除
			// 第i个没拆的最短时间是前一段的最短时间+后面的时间
			dp[i][0][j]=min(dp[i-1][0][j],dp[i-1][1][j])+(d[i+1]-d[i])*a[i];
			
			// 移除
			for(int x=0;x<i;x++)
			{
				if(j>=i-x) // 从x到i+1间的路标全都移除了，所以算x+1到i+1的时间
				{
					dp[i][1][j]=min(dp[i][1][j],dp[x][0][j-(i-x)]+(d[i+1]-d[x+1])*a[x]);
				}
			}
		}
	}
	int ans=1e18;
	for(int i=0;i<=k;i++)
	{
		ans=min({ans,dp[n][0][i],dp[n][1][i]});
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