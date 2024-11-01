/*
 * @Author: dsaDadas11
 * @Date: 2024-08-29 17:36:02
 * @LastEditTime: 2024-08-29 17:42:58
 * @Description: go for it!
 */
// URL:https://www.lanqiao.cn/problems/178/learning/

// dfs
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int dx[9]={1,-1,0,0};
int dy[9]={0,0,-1,1};
int n;
char mp[M][M];
bool vis[M][M];
bool check(int x,int y)
{
	if(mp[x-1][y]=='#'&&mp[x+1][y]=='#'&&mp[x][y-1]=='#'&&mp[x][y+1]=='#') return 1;
	return 0;
}
bool flag=0;
int ans=0;
void dfs(int x,int y)
{
	if(check(x,y)) flag=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>n) continue;
		if(vis[xx][yy]||mp[xx][yy]!='#') continue;
		vis[xx][yy]=1;
		dfs(xx,yy);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]=='#'&&!vis[i][j])
			{
				flag=0;
				vis[i][j]=1;
				dfs(i,j);
				if(!flag) ans++;
			}
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

// bfs
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int dx[9]={1,-1,0,0};
int dy[9]={0,0,-1,1};
int n;
char mp[M][M];
bool vis[M][M];
bool check(int x,int y)
{
	if(mp[x-1][y]=='#'&&mp[x+1][y]=='#'&&mp[x][y-1]=='#'&&mp[x][y+1]=='#') return 1;
	return 0;
}
bool flag=0;
int ans=0;
void bfs(int x,int y)
{
	queue<pair<int,int> > q;
	q.push({x,y});
	while(!q.empty())
	{
		auto [x1,y1]=q.front();
		q.pop();
		if(check(x1,y1)) flag=1;
		for(int i=0;i<4;i++)
		{
			int xx=x1+dx[i];
			int yy=y1+dy[i];
			if(mp[xx][yy]!='#'||vis[xx][yy]) continue;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]=='#'&&!vis[i][j])
			{
				flag=0;
				vis[i][j]=1;
				bfs(i,j);
				if(!flag) ans++;
			}
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