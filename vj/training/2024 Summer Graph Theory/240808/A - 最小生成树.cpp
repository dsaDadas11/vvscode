/*
 * @Author: dsaDadas11
 * @Date: 2024-08-08 14:16:02
 * @LastEditTime: 2024-08-08 14:16:08
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
int u,v,w;
struct Edge
{
	int v,w;
	bool operator<(const Edge&a) const
	{
		return w>a.w;
	}
};
vector<Edge> g[N];
bool vis[N];
int ans;
void prim()
{
	priority_queue<Edge> pq;
	pq.push({1,0});
	while(!pq.empty())
	{
		int u=pq.top().v;
		int val=pq.top().w;
		pq.pop();
		if(vis[u]) continue;
		ans+=val;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v=it.v;
			int w=it.w;
			if(vis[v]) continue;
			pq.push({v,w});
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	prim();
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cout<<"orz"<<endl;
			return;
		}
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