/*
 * @Author: dsaDadas11
 * @Date: 2024-09-13 11:15:03
 * @LastEditTime: 2024-09-13 11:15:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=6e3+7;
constexpr int M=2e3+7;
int n;
int r[N];
vector<int> g[N];
int dp[N][2];
void dfs(int u)
{
	dp[u][0]=0;
	dp[u][1]=r[u];
	for(int v:g[u])
	{
		dfs(v);
		// u去
		dp[u][1]+=dp[v][0];
		// u不去
		dp[u][0]+=max(dp[v][1],dp[v][0]);
	}
}
int fa[N];
int find_fa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find_fa(fa[x]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	for(int i=1;i<=n;i++) fa[i]=i;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>v>>u;
		g[u].push_back(v);
		fa[v]=u;
	}
	int fax=find_fa(1);
	dfs(fax);
	cout<<max(dp[fax][1],dp[fax][0])<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}