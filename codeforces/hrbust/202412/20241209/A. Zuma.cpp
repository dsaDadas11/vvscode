/*
 * @Author: dsaDadas11
 * @Date: 2024-12-09 21:30:34
 * @LastEditTime: 2024-12-09 21:47:47
 * @Description: go for it!
 */
/*
 区间dp的板子题，不过需要注意[i,i]和[i,i+1]需要先处理出来
 因为后面要用到从[i+1,j-1]转移到[i,j]，区间最小跨度为3，因此要把区间长度为1，2的都预处理
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int c[507];
int dp[507][507];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1;
	}

	for(int i=1;i<n;i++)
	{
		if(c[i]!=c[i+1]) dp[i][i+1]=2;
		else dp[i][i+1]=1;
	}

	for(int len=2;len<=n;len++)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			if(c[i]==c[j]) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			for(int k=i;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}