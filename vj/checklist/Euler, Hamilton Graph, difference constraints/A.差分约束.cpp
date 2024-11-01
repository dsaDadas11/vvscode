/*
 * @Author: dsaDadas11
 * @Date: 2024-08-15 14:59:46
 * @LastEditTime: 2024-08-15 15:00:35
 * @Description: go for it!
 */
/*
 建图：由xi-xj<=c 化为 xi<=xj+c 即从xj到xi建一条边权为c的边
 如果有 xi-xj<c 可化为 xi-xj<=c-1
 如果有 xi-xj>=c 两边同时乘-1化为 xj-xi<=-c
 如果有 xi-xj=c 则可拆成 xi-xj<=c 和 xi-xj>=c
 值得一提的点是，我们需要加入v0节点指向其他所有节点并建边权为0的边
 因此，判断负环(差分约束是否有解时) 需要cnt[v]>=n+1 才能判定，因为有n+1个节点
 因此一组解答案为dist[1]到dist[n]
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e3+7;
constexpr int M=2e3+7;
int n,m;
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
	dist[0]=0;
	queue<int> q;
	q.push(0);
	vis[0]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto [v,w]:g[u])
		{
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n+1) return 1;
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
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>v>>u>>w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++)
	{
		g[0].push_back({i,0});
	}
	if(spfa()) cout<<"NO"<<endl;
	else
	{
		for(int i=1;i<=n;i++)
		{
			cout<<dist[i]<<' ';
		}
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}