/*
 * @Author: dsaDadas11
 * @Date: 2024-05-14 20:05:56
 * @LastEditTime: 2025-01-20 15:56:22
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,m;
int a[M][M],b[M][M];
bool vis[M][M];
struct op
{
	int x,y;
	int cost;
};
bool bfs()
{
	queue<op> q;
	q.push({1,1,b[1][1]});
	while(!q.empty())
	{
		auto [x,y,cost]=q.front();
		q.pop();
		
		if(x<n)
		{
			// 往下走
			if(vis[x+1][y]) continue;
			if(a[x+1][y]-a[1][1]-cost-b[x+1][y]>=0)
			{
				q.push({x+1,y,cost+b[x+1][y]});
				vis[x+1][y]=1;	
			}
		}
		if(y<m)
		{
			// 往右走
			if(vis[x][y+1]) continue;
			if(a[x][y+1]-a[1][1]-cost-b[x][y+1]>=0)
			{
				q.push({x,y+1,cost+b[x][y+1]});
				vis[x][y+1]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i][m]) return 1;
	}
	for(int j=1;j<=m;j++)
	{
		if(vis[n][j]) return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
		}
	}
	if(bfs()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}