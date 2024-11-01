/*
 * @Author: dsaDadas11
 * @Date: 2024-03-16 14:42:14
 * @LastEditTime: 2024-03-16 14:42:22
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct edge
{
	int v,w;
};
vector<edge> g[N];
int dist[N],cnt[N];
bool st[N];
bool spfa(int n)
{
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	memset(cnt,0,sizeof cnt);
	queue<int> q;
	dist[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		st[u]=0;
		for(int i=0;i<(int)g[u].size();i++)
		{
			int v=g[u][i].v,w=g[u][i].w;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n) return 1;
				if(!st[v])
				{
					q.push(v);
					st[v]=1;
				}
			}
		}
	}
	return 0;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		if(w>=0) g[v].push_back({u,w});
	}
	if(spfa(n)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}