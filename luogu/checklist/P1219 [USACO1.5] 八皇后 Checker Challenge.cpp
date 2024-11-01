/*
 * @Author: dsaDadas11
 * @Date: 2024-08-29 18:25:46
 * @LastEditTime: 2024-08-29 18:25:59
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[7]={0,0,1,-1};
int dy[7]={1,-1,0,0};
int n;
int mp[20][20];
bool vis[20];
bool check(int x,int y)
{
	int xx=x,yy=y;
	while(xx>=1&&yy>=1)
	{
		if(mp[xx][yy]) return 0;
		xx--,yy--;
	}
	xx=x,yy=y;
	while(xx>=1&&yy<=n)
	{
		if(mp[xx][yy]) return 0;
		xx--,yy++;
	}
	xx=x,yy=y;
	while(xx<=n&&yy<=n)
	{
		if(mp[xx][yy]) return 0;
		xx++,yy++;
	}
	xx=x,yy=y;
	while(xx<=n&&yy>=1)
	{
		if(mp[xx][yy]) return 0;
		xx++,yy--;
	}
	return 1;
}
int res=0;
void out()
{
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(mp[i][j]) cout<<j<<' ';
			}
		}
		cout<<endl;
}
void dfs(int x)
{
	if(x==n+1)
	{
		res++;
		if(res<=3) out();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]||!check(x,i)) continue;
		vis[i]=1;
		mp[x][i]=1;
		dfs(x+1);
		vis[i]=0;
		mp[x][i]=0;
	}
}
void solve()
{
	cin>>n;
	dfs(1);
	cout<<res<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}