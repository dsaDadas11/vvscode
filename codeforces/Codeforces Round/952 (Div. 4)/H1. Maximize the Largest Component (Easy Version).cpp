/*
 * @Author: dsaDadas11
 * @Date: 2024-11-11 20:58:59
 * @LastEditTime: 2024-11-11 21:00:54
 * @Description: go for it!
 */
/*
 1700的模拟就这样吧，没啥难度
 卡常卡的有点狠
*/
#include<bits/stdc++.h>
#define endl '\n'
// #define ll long long
// #define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[7]={0,0,1,-1};
int dy[7]={-1,1,0,0};
int n,m;
int cnt,sum;
int x1,y11;
void solve()
{
	cin>>n>>m;
	cnt=0;
	vector<vector<char> > ch(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ch[i][j];
		}
	}
	vector<vector<int> > vis(n+1,vector<int>(m+1));
	vector<int> mp; // 记录一个连通块中有多少个节点
	mp.push_back(0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ch[i][j]=='#'&&!vis[i][j])
			{
				++cnt;
				queue<pair<int,int> > q;
				sum=0;
				q.push({i,j});
				while(!q.empty())
				{
					auto [xx,yy]=q.front();
					q.pop();
					if(vis[xx][yy]) continue;
					++sum;
					vis[xx][yy]=cnt;
					for(int i=0;i<4;i++)
					{
						x1=xx+dx[i];
						y11=yy+dy[i];
						if(x1<1||x1>n||y11<1||y11>m) continue;
						if(ch[x1][y11]=='.') continue;
						if(vis[x1][y11]) continue;
						q.push({x1,y11});
					}
				}
				mp.push_back(sum);
			}
		}
	}
	// 暴力枚举每一行
	int ans=0;
	int res=0;
	int up=0,down=0;
	map<int,bool> visx;
	for(int i=1;i<=n;i++)
	{
		res=0;
		up=i-1,down=i+1;
		visx.clear();
		for(int j=1;j<=m;j++)
		{
			if(up>=1&&vis[up][j]&&!visx[vis[up][j]]) res+=mp[vis[up][j]],visx[vis[up][j]]=1;
			if(down<=n&&vis[down][j]&&!visx[vis[down][j]]) res+=mp[vis[down][j]],visx[vis[down][j]]=1;
			if(ch[i][j]!='#') res++;
		}
		for(int j=1;j<=m;j++)
		{
			if(ch[i][j]=='#'&&visx[vis[i][j]]==0) res++;
		}
		ans=max(ans,res);
	}
	
	// 暴力枚举每一列
	int lx=0,rx=0;
	for(int j=1;j<=m;j++)
	{
		res=0;
		lx=j-1,rx=j+1;
		visx.clear();
		for(int i=1;i<=n;i++)
		{
			if(lx>=1&&vis[i][lx]&&!visx[vis[i][lx]]) res+=mp[vis[i][lx]],visx[vis[i][lx]]=1;
			if(rx<=m&&vis[i][rx]&&!visx[vis[i][rx]]) res+=mp[vis[i][rx]],visx[vis[i][rx]]=1;
			if(ch[i][j]!='#') res++;
		}
		for(int i=1;i<=n;i++)
		{
			if(ch[i][j]=='#'&&visx[vis[i][j]]==0) res++;
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}