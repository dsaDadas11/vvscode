/*
 * @Author: dsaDadas11
 * @Date: 2024-03-16 17:23:21
 * @LastEditTime: 2024-03-16 17:23:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=100+7;
constexpr int inf=1e9;
int n,m;
int dist[M][M];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) dist[i][j]=0;
			else dist[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		dist[v][u]=min(dist[v][u],w);
		dist[u][v]=min(dist[u][v],w);
	}
	floyd();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dist[i][j]<<' ';
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