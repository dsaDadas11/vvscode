/*
 * @Author: dsaDadas11
 * @Date: 2024-07-25 20:38:11
 * @LastEditTime: 2024-07-25 20:38:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
char mp[N][N];
int n,m,p;
int s[N],ans[N];
int dx[7]={0,0,1,-1};
int dy[7]={1,-1,0,0};
struct op
{
	int x,y;
	int step;
};
queue<pair<int,int> > pos[N];
queue<op> q;
void bfs(int pp)
{
	while(!q.empty())
	{
		int x=q.front().x;
		int y=q.front().y;
		int step=q.front().step;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if (xx<1||xx>n||yy<1||yy>m||mp[xx][yy]!='.') continue;
			mp[xx][yy]=(char)('0'+pp);
			if(step) q.push({xx,yy,step-1});
			else pos[pp].push({xx,yy});
		}
		
	}
}
void solve()
{
	cin>>n>>m>>p;
	for(int i=1;i<=p;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]<='9'&&mp[i][j]>='1')
			{
				int t=mp[i][j]-'0';
				pos[t].push({i,j});
			}
		}
	}
	while(1)
	{
		bool flag=0;
		for(int i=1;i<=p;i++)
		{
			while(!pos[i].empty())
			{
				int x=pos[i].front().first;
				int y=pos[i].front().second;
				pos[i].pop();
				q.push({x,y,s[i]-1});
				flag=1;
			}
			if(flag) bfs(i);
		}
		if(!flag) break;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='#') continue;
			ans[mp[i][j]-'0']++;
			//cout<<mp[i][j]<<' ';
		}
		//cout<<endl;
	}
	for(int i=1;i<=p;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}