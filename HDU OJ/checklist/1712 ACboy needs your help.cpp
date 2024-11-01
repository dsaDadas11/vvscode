/*
 * @Author: dsaDadas11
 * @Date: 2024-09-02 22:43:47
 * @LastEditTime: 2024-09-02 23:00:14
 * @Description: go for it!
 */
// 分组背包
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[107][107];
int dp[107];
void solve()
{
	while(cin>>n>>m&&n&&m)
	{
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=0;j--) // 背包容量
			{
				for(int k=1;k<=m;k++)
				{
					if(j>=k) dp[j]=max(dp[j],dp[j-k]+a[i][k]);
				}
			}
		}
		cout<<dp[m]<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}