/*
 * @Author: dsaDadas11
 * @Date: 2024-11-13 16:31:54
 * @LastEditTime: 2024-11-13 16:38:08
 * @Description: go for it!
 */
/*
 解题思路：
 这道题要我们找某一行和某一列的最大值，直接暴力(n*m)^2肯定是不行的，
 那么我们可以想到预处理一下，假如我们选的(i,j)包含了一个连通块，那么这个连通块肯定在i和j中都被算过一次，
 那么我们将多出的这一次减掉即可，然后再特判一下(i,j)这个位置是否能被算两次
 标记每个连通块的上下左右边界，
 需要注意的是：每个连通块会对l1-1,l2+1,r1-1,r2+1产生贡献，因此在处理差分区间的时候要将这一部分加上，
 但是处理到0后，想要使用前缀和是不行的，因为数组访问-1越界了，因此我们将坐标整体往右下角移，即i+1,j+1
 要巩固巩固二维差分和二维前缀和了，一开始居然写错了....
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
	vector<vector<int> > d(n+5,vector<int>(m+5)); // 差分区间
	vector<int> mp; // 记录一个连通块中有多少个节点
	mp.push_back(0);
	int mx1=0,mx2=0;
	int my1=0,my2=0;
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
				mx1=mx2=i;
				my1=my2=j;
				while(!q.empty())
				{
					auto [xx,yy]=q.front();
					q.pop();
					if(vis[xx][yy]) continue;
					++sum;
					mx1=min(mx1,xx),mx2=max(mx2,xx);
					my1=min(my1,yy),my2=max(my2,yy);
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
				mx2+=2;
				my2+=2;
				d[mx1][my1]+=sum;
				d[mx1][my2+1]-=sum;
				d[mx2+1][my1]-=sum;
				d[mx2+1][my2+1]+=sum;
				mp.push_back(sum);
			}
		}
	}
	
	// 二维前缀和预处理差分区间
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=m+1;j++)
		{
			d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
		}
	}
	
	// 暴力枚举每一行
	vector<int> row(n+1); // 存每一行的值
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
		row[i]=res;
	}
	
	// 暴力枚举每一列
	vector<int> col(m+1); // 存每一列的值
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
		col[j]=res;
	}
	
	
	// 暴力找每一列和每一行的最值
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			res=row[i]+col[j]-d[i+1][j+1];
			// 特判(i,j)
			if(!vis[i][j]) res-=1;
			ans=max(ans,res);
		}
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