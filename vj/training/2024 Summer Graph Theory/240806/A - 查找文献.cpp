/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-08-06 14:06:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int u,v;
vector<int> g[N];
bool vis[N],vis2[N];
void dfs(int x)
{
	sort(g[x].begin(),g[x].end());
	cout<<x<<' ';
	vis[x]=1;
	for(auto it:g[x])
	{
		if(vis[it]) continue;
		vis[it]=1;
		dfs(it);
	}
}
queue<int> q;
void bfs()
{
	q.push(1);
	vis2[1]=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		cout<<t<<' ';
		for(auto it:g[t])
		{
			if(vis2[it]) continue;
			vis2[it]=1;
			q.push(it);
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
	}
	dfs(1);
	cout<<endl;
	bfs();
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}