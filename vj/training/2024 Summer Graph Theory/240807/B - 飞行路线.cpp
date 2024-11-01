/*
 * @Author: dsaDadas11
 * @Date: 2024-08-07 14:42:18
 * @LastEditTime: 2024-08-07 14:45:57
 * @Description: go for it!
 */
/*
 分层图最短路板子题,用到dp的思想
 dis(i,j)=min{min{dis(from,j−1)},min{dis(from,j+w)}}
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e4+7;
constexpr int M=2e3+7;
int n,m,k;
int s,t;
int u,v,w;
int dist[N][17];
bool vis[N][17];
struct Edge
{
	int v,w;
};
vector<Edge> g[N];
struct po
{
	int v,w,cnt;
	bool operator<(const po&a) const
	{
		return w>a.w;
	}
};
void dijkstra()
{
	memset(dist,0x3f,sizeof dist);
	dist[s][0]=0;
	priority_queue<po> pq;
	pq.push({s,0,0});
	while(!pq.empty())
	{
		int u=pq.top().v;
		int nowcnt=pq.top().cnt;
		pq.pop();
		if(vis[u][nowcnt]) continue;
		vis[u][nowcnt]=1;
		for(auto it:g[u])
		{
			int v=it.v;
			int w=it.w;
			// 免费的
			if(nowcnt<k&&dist[v][nowcnt+1]>dist[u][nowcnt])
			{
				dist[v][nowcnt+1]=dist[u][nowcnt];
				pq.push({v,dist[v][nowcnt+1],nowcnt+1});
			}
			// 不免费
			if(dist[v][nowcnt]>dist[u][nowcnt]+w)
			{
				dist[v][nowcnt]=dist[u][nowcnt]+w;
				pq.push({v,dist[v][nowcnt],nowcnt});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>k;
	cin>>s>>t;
	++s,++t;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		++u,++v;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dijkstra();
	int ans=1e18;
	for(int i=0;i<=k;i++) ans=min(ans,dist[t][i]);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}