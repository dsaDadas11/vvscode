/*
 * @Author: dsaDadas11
 * @Date: 2024-11-20 22:24:37
 * @LastEditTime: 2024-11-20 22:24:57
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
vector<int> g[67];
int dp[67][N];
int w[N],val[N];
void dfs(int u)
{
	for(auto v:g[u])
	{
		// 买了w[v]的钱后把状态下放
		for(int i=n-w[v];i>=0;i--)
		{
			dp[v][i]=dp[u][i]+val[v];
		}
		dfs(v);
		for(int i=n;i>=w[v];i--)
		{
			dp[u][i]=max(dp[u][i],dp[v][i-w[v]]);
		}
	}
	
}
void solve()
{
	cin>>n>>m;
	int p,q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]>>p>>q;
		val[i]=w[i]*p;
		g[q].push_back(i);
	}
	dfs(0);
	cout<<dp[0][n]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
因为只有三层，所以可以用for循环来做

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
vector<int> g[67];
int dp[67][N];
int w[N],val[N];

void solve()
{
	cin>>n>>m;
	int p,q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]>>p>>q;
		val[i]=w[i]*p;
		g[q].push_back(i);
	}
	for(auto fa:g[0])
	{
		for(int i=n-w[fa];i>=0;i--)
		{
			dp[fa][i]=dp[0][i]+val[fa];
		}
		for(auto v:g[fa])
		{
			for(int i=n-w[v]-w[fa];i>=0;i--)
			{
				dp[v][i]=dp[fa][i]+val[v];
			}
			for(int i=n-w[fa];i>=w[v];i--)
			{
				dp[fa][i]=max(dp[fa][i],dp[v][i-w[v]]);
			}
		}
		for(int i=n;i>=w[fa];i--)
		{
			dp[0][i]=max(dp[0][i],dp[fa][i-w[fa]]);
		}
	}
	cout<<dp[0][n]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/