/*
 * @Author: dsaDadas11
 * @Date: 2024-10-28 21:47:24
 * @LastEditTime: 2024-10-28 21:49:36
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/P1002
/*
 解题思路：
 唯一一道之前搞优化性能把long long关了的然后wa了的题，
 不开long long见祖宗
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int nx,ny;
bool vis[27][27];
int dp[27][27];
int dfs(int x,int y)
{
	if(x<0||x>n||y<0||y>m) return 0;
	if(vis[x][y]) return 0;
	if(dp[x][y]) return dp[x][y];
	dp[x][y]=dfs(x-1,y)+dfs(x,y-1);
	return dp[x][y];
}
void solve()
{
	cin>>n>>m>>nx>>ny;
	vis[nx+2][ny+1]=1;
	if(nx>=2) vis[nx-2][ny+1]=1;
	if(ny>=1) vis[nx+2][ny-1]=1;
	if(ny>=1&&nx>=2) vis[nx-2][ny-1]=1;
	vis[nx][ny]=1;
	vis[nx+1][ny+2]=1;
	if(nx>=1) vis[nx-1][ny+2]=1;
	if(ny>=2) vis[nx+1][ny-2]=1;
	if(nx>=1&&ny>=2) vis[nx-1][ny-2]=1;
	
	for(int i=0;i<=n;i++)
	{
		if(vis[i][0]) break;
		dp[i][0]=1;
	}
	for(int j=0;j<=m;j++)
	{
		if(vis[0][j]) break;
		dp[0][j]=1;
	}
	
	dfs(n,m);

	cout<<dp[n][m]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}