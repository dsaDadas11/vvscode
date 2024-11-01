/*
 * @Author: dsaDadas11
 * @Date: 2024-03-15 13:54:43
 * @LastEditTime: 2024-03-15 13:56:23
 * @Description: go for it!
 */
//dijkstra堆优化版（用于稀疏图）
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
typedef pair<int,int> pll; //距离，编号
struct Edge
{
	int v,w;
};
vector<Edge> g[N];
int dist[N];
int st[N];
void dijkstra(int n,int s)
{
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	priority_queue<pll,vector<pll>,greater<pll> > q;
	q.push({0,s});
	while(!q.empty())
	{
		pll t=q.top();
		q.pop();
		int u=t.second;
		if(st[u]) continue;
		st[u]=1;
		for(auto i :g[u])
		{
			int v=i.v,w=i.w;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
void solve()
{
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	dijkstra(n,s);
	for(int i=1;i<=n;i++) cout<<dist[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
dijkstra朴素版，用于稠密图

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=100+7;
constexpr int M=2e3+7;
int g[N][N];
int dist[N];
bool st[N]; //标记最短路
void dijkstra(int n,int s)
{
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	for(int i=1;i<=n;i++)
	{
		int t=-1;
		for(int j=1;j<=n;j++)
		{
			if(!st[j]&&(t==-1||dist[t]>dist[j]))
			{
				t=j;
			}
		}
		st[t]=1;
		if(t==n) break;
		for(int j=1;j<=n;j++)
		{
			if(g[t][j]==-1) continue;
			if(dist[j]>dist[t]+g[t][j])
			{
				dist[j]=dist[t]+g[t][j];
			}
		}
	}
}
void solve()
{
	int n,m,s;
	cin>>n>>m>>s;
	memset(g,-1,sizeof g);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(g[u][v]==-1) g[u][v]=w;
		else g[u][v]=min(g[u][v],w);
	}
	dijkstra(n,s);
	for(int i=1;i<=n;i++) cout<<dist[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

*/