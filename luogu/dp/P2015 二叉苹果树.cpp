/*
 * @Author: dsaDadas11
 * @Date: 2024-09-13 10:30:09
 * @LastEditTime: 2024-09-13 10:31:42
 * @Description: go for it!
 */
/*
 树形dp例题
 dp[u][j]表示第u个节点及其子树能留j条枝时能留住的苹果数量
 sum[u]表示u上有多少枝（边）
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q;
struct Edge
{
	int v,w;
};
vector<Edge> g[N];
int dp[207][207];
int sum[207];
void dfs(int u,int fa)
{
	for(auto it:g[u])
	{
		int v=it.v,w=it.w;
		if(v==fa) continue;
		dfs(v,u);
		sum[u]+=sum[v]+1;
		for(int j=sum[u];j>=0;j--)
		{
			for(int k=0;k<j;k++)
			{
				dp[u][j]=max(dp[u][j],dp[u][j-1-k]+dp[v][k]+w);
			}
		}
	}
}
void solve()
{
	cin>>n>>q;
	int u,v,w;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,0);
	cout<<dp[1][q]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}