/*
 * @Author: dsaDadas11
 * @Date: 2024-05-14 20:05:56
 * @LastEditTime: 2024-05-14 20:08:33
 * @Description: go for it!
 */
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define endl '\n'
#define buff ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=1e3+7;
int n,m;
int a[N][N];
int b[N][N];
struct pp{
	int x;
	int y;
	int val;
};
int vis[N][N];
int mp[N][N];
pp aa,bb;
queue<pp> q;
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
	q.push({1,1,a[1][1]});
	vis[1][1]=1;
	int xx,yy;
	int va;
	while(!q.empty())
	{
		aa=q.front();
		q.pop();
		xx=aa.x,yy=aa.y;
		va=aa.val;
		if(a[xx+1][yy]-a[1][1]-va-b[xx+1][yy]>=0&&mp[xx+1][yy]==0)
		{
			q.push({xx+1,yy,va+b[xx+1][yy]});
			vis[xx+1][yy]=1;
			mp[xx+1][yy]=1;
		}
		if(a[xx][yy+1]-a[1][1]-va-b[xx][yy+1]>=0&&mp[xx+1][yy]==0)
		{
			q.push({xx,yy+1,va+b[xx][yy+1]});
			vis[xx][yy+1]=1;
			mp[xx][yy+1]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(vis[n][i])
		{
			cout<<"YES"<<'\n';
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i][m])
		{
			cout<<"YES"<<'\n';
			return;
		}
	}
	cout<<"NO"<<'\n';
	return ;
}

signed main()
{
	buff;
	int tt = 1;
	// cin >> tt;
	while (tt--)
	{
		solve();
	}
	return 0;
} 