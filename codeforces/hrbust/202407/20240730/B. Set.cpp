/*
 * @Author: dsaDadas11
 * @Date: 2024-07-30 18:49:35
 * @LastEditTime: 2024-07-30 18:49:45
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int dp[1850];
void solve()
{
	cin>>n;
	int sum=n*(n+1)/2;
	if(sum%2)
	{
		cout<<"0"<<endl;
		return;
	}
	sum/=2;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=i;j--)
		{
			dp[j]+=dp[j-i];
		}
	}
	cout<<dp[sum]/2<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}