/*
 * @Author: dsaDadas11
 * @Date: 2024-03-11 15:22:58
 * @LastEditTime: 2024-03-11 15:23:04
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
int dp[N+7];
void solve()
{
	int n;
	dp[0]=0,dp[1]=0,dp[2]=0,dp[3]=0,dp[4]=1;
	for(int i=1;i<=N;i++)
	{
		if(i>=16) dp[i]=max(dp[i],dp[i-16]+9);
		if(i>=8) dp[i]=max(dp[i],dp[i-8]+3);
		if(i>=4) dp[i]=max(dp[i],dp[i-4]+1);
	}
	while(cin>>n)
	{
		cout<<dp[n]<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}