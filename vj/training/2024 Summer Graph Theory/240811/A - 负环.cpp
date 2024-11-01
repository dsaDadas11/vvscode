/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-08-11 14:58:41
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e3+7;
constexpr int M=2e3+7;
int n,m;
int u,v,w;
struct Edge
{
	int v,w;
};
vector<Edge> g[N];
int dist[N],cnt[N];
bool vis[N];
bool spfa()
{
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	dist[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto it:g[u])
		{
			int v=it.v;
			int w=it.w;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n) return 1;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++) g[i].clear();
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		if(w>=0) g[v].push_back({u,w});
	}
	if(spfa()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}