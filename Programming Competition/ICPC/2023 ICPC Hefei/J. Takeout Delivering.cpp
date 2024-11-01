/*
 * @Author: dsaDadas11
 * @Date: 2024-10-24 14:24:56
 * @LastEditTime: 2024-10-24 14:37:58
 * @Description: go for it!
 */
/*
 解题思路：
 这道题内存卡的很死，看数据范围定内存，
 题意：找1-n中路径的两个最大值，使它们相加最小，
 我们可以枚举每一条边来找答案：
 1.我们将这条边假定为最大的权值，然后找其他边的次大的权值，如果这个次大权值大于最大权值则不合法
 2.我们可以预处理一个点到1和n的距离(此距离为最大权值)，次大权值就在max(dis1[u],dis2[v])或max(dis1[v],dis2[u])中
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define pll pair<int,int>
using namespace std;
constexpr int N=3e5+7;
constexpr int M=1e6+7;
int n,m;
struct Edge
{
	int v,w;
};
struct op
{
	int x,y,z;
}e[M];
vector<Edge> g[N];
bool st[N];
int dis1[N],dis2[N];
void dijkstra(int s,int *dis)
{
	for(int i=0;i<=n+5;i++) dis[i]=1e18;
	dis[s]=0;
	priority_queue<pll,vector<pll>,greater<pll> > q;
	q.push({0,s});
	while(!q.empty())
	{
		pll t=q.top();
		q.pop();
		int u=t.second;
		if(st[u]) continue;
		st[u]=1;
		for(auto i:g[u])
		{
			int v=i.v,w=i.w;
			if(dis[v]>max(dis[u],w))
			{
				dis[v]=max(dis[u],w);
				q.push({dis[v],v});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[i]={u,v,w};
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dijkstra(1,dis1);
	for(int i=0;i<=n+5;i++) st[i]=0;
	dijkstra(n,dis2);
	int ans=1e18;
	int tmp=0;
	for(int i=1;i<=m;i++)
	{
		auto [u,v,w]=e[i];
		// 将w看作最大的边
		tmp=min(max(dis1[u],dis2[v]),max(dis1[v],dis2[u]));
		if(tmp<=w) ans=min(ans,tmp+w);
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