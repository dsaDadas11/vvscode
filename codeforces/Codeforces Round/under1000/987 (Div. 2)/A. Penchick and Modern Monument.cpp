/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-11-15 20:51:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e2+7;
constexpr int M=2e3+7;
int n;
int h[N];
int dp[N];
void solve()
{
	cin>>n;
	for(int i=0;i<=n+5;i++) dp[i]=1;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(h[i]>=h[j])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,dp[i]);
	cout<<n-maxn<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}