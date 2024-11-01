/*
 * @Author: dsaDadas11
 * @Date: 2024-07-30 18:50:11
 * @LastEditTime: 2024-07-30 18:50:23
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,b,mod;
int a[M];
int dp[2][507][507]; // 程序员编号 累计任务代码数 累计错误总数
void solve()
{
	cin>>n>>m>>b>>mod;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int p=i%2;
		int pre=p^1;
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=b;k++)
			{
				dp[p][j][k]=dp[pre][j][k];
				if(j>=1&&k>=a[i])
				{
					dp[p][j][k]+=dp[p][j-1][k-a[i]];
					dp[p][j][k]%=mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=b;i++)
	{
		ans+=dp[n%2][m][i];
		ans%=mod;
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