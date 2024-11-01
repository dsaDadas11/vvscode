/*
 * @Author: dsaDadas11
 * @Date: 2024-08-31 12:07:54
 * @LastEditTime: 2024-09-02 18:48:43
 * @Description: go for it!
 */
/*
 01背包二维dp
 从小遍历到大和从大遍历到小都一样
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int n,C;
int w[N],c[N];
int dp[N][N];
void solve()
{
	cin>>n>>C;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=C;j++)
		{
			if(j<c[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
		}
	}
	cout<<dp[n][C]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
滚动数组
为什么从大遍历到小呢，因为这样才能保证每个大状态只能被小的状态更新一次
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int n,C;
int w[N],c[N];
int dp[N];
void solve()
{
	cin>>n>>C;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=C;j>=c[i];j--)
		{
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		}
	}
	cout<<dp[C]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/