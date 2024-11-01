/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-17 15:27:33
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int k,n,m;
int a[N],sum[N];
bool vis[N];
vector<int> g[N];
void dfs(int x)
{
	vis[x]=1,sum[x]++;
	for(int i=0;i<(int)g[x].size();i++)
	{
		int to=g[x][i];
		if(!vis[to]) dfs(to);
	}
}
void solve()
{
	cin>>k>>n>>m; //牛，牧场，路
	for(int i=1;i<=k;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int u,v; cin>>u>>v;
		g[u].push_back(v);
	}
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		memset(vis,0,sizeof vis);
		dfs(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]==k) ans++;
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