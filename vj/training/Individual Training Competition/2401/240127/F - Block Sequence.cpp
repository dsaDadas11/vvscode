/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-27 22:20:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],dp[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	fill(dp+1,dp+1+n,1e18);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=min(dp[i],dp[i-1]+1);
		if(i+a[i]<=n) dp[i+a[i]]=min(dp[i-1],dp[i+a[i]]);
	}
	int ans=1e18;
	for(int i=1;i<=n;i++) ans=min(ans,dp[i]+n-i);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}