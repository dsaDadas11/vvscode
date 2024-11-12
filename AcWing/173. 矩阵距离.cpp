/*
 * @Author: dsaDadas11
 * @Date: 2024-11-06 13:29:44
 * @LastEditTime: 2024-11-06 13:32:22
 * @Description: go for it!
 */
/*
 解题思路：
 多源bfs问题：同时将所有起点加入队列即可
 要求0到最近的1的距离，因为正着来要遍历所有0点才行，肯定超时，
 所以我们遍历1，将所有1都push进队列，然后从这些1一直往外扩，先扩到的点一定是最短路
*/
// URL：https://www.acwing.com/problem/content/175/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,m;
int dis[M][M];
string s[M];
bool vis[M][M];
int dx[7]={0,0,-1,1};
int dy[7]={-1,1,0,0};
void bfs()
{
	queue<pair<int,int> > q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='1')
			{
				q.push({i,j});
			}
		}
	}
	while(!q.empty())
	{
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(vis[xx][yy]) continue;
			if(xx<1||xx>n||yy<1||yy>m) continue;
			vis[xx][yy]=1;
			if(s[xx][yy]=='0') dis[xx][yy]=dis[x][y]+1;
			q.push({xx,yy});
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=' '+s[i];
	}
	bfs();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<dis[i][j]<<' ';
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