/*
 * @Author: dsaDadas11
 * @Date: 2025-04-05 19:34:21
 * @LastEditTime: 2025-04-05 19:36:16
 * @Description: go for it!
 */
/*
 解题思路：
 n为 10直接暴力
 怎么判断是否交叉？如果 (x1,y1),(x2,y2)与 (x3,y3),(x4,y4)交叉的话
 则有 x1+x2=x3+x4 y1+y2=y3+y4,因此用 overlap数组标记一下即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[17]={-1,-1,0,1,1,1,0,-1};
int dy[17]={0,1,1,1,0,-1,-1,-1};
int n,k;
bool vis[17][17];
bool overlap[17][17];
int a[17][17];
vector<int> ans;
int sum;
bool check(int x,int y)
{
	return x<1||x>n||y<1||y>n;
}
void dfs(int x,int y)
{
	if(x==n&&y==n&&sum==n*n-1)
	{
		for(auto i:ans) cout<<i;
		cout<<endl;
		exit(0);
	}
	vis[x][y]=1;
	
	for(int i=0;i<8;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(check(xx,yy)) continue;
		if(vis[xx][yy]) continue;
		if((a[x][y]+1)%k!=a[xx][yy]) continue;
		int sx=xx+x,sy=yy+y;
		if(overlap[sx][sy]) continue;
		overlap[sx][sy]=1;
		vis[xx][yy]=1;
		ans.push_back(i);
        sum++;
		dfs(xx,yy);
        sum--;
		ans.pop_back();
		overlap[sx][sy]=0;
		vis[xx][yy]=0;
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(1,1);
	cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}