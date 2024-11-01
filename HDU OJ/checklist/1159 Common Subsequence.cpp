/*
 * @Author: dsaDadas11
 * @Date: 2024-09-03 14:25:57
 * @LastEditTime: 2024-09-03 14:26:06
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
string x,y;
int dp[M][M]; // 表示x的前i个位置和y的前j个位置的最长公共子序列
void solve()
{
	memset(dp,0,sizeof dp);
	int lenx=x.size(),leny=y.size();
	x=' '+x,y=' '+y;
	for(int i=1;i<=lenx;i++)
	{
		for(int j=1;j<=leny;j++)
		{
			if(x[i]==y[j]) dp[i][j]=dp[i-1][j-1]+1;
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[lenx][leny]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>x>>y){solve();}
	return 0;
}