/*
 * @Author: dsaDadas11
 * @Date: 2024-12-07 15:51:51
 * @LastEditTime: 2024-12-07 16:08:18
 * @Description: go for it!
 */
/*
 解题思路：
 看一眼求路径中最大的总度数，能想到用树形dp解决
 有两种情况
 1.只选一个点，那么d[u]即为答案
 2.选两个不相同的点a,b，那么答案即为 度数和减去重复的度数贡献
 假如两个点是在一起的 2->3 2会对3产生度数贡献，3也会对2产生度数贡献，删去边后这两个贡献不存在了，因此贡献总和为 d[2]+d[3]-2

 设dp[i]为 i节点能得到的最大连通分量个数
 当 i节点只选择自己时 dp[i]=g[i].size()
 在写状态转移方程前，我们可以想到一个u，可能有多个子节点v对其产生贡献，但u最多只能选2个子节点(不然不能形成路径了)
 因此在遍历时我们只能将一个子节点转移至u，用maxx转移其他子节点：
 maxx=max(maxx,dp[u]+dp[v]-2); // 可能u以一条子链，连接至v这条子链
 dp[u]=max(dp[u],dp[v]+(int)g[u].size()-2); // 然后u更新，看是否连接v这条子链

*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
vector<int> g[N];
int dp[N];
int maxx;
void dfs(int u,int fax)
{
	dp[u]=(int)g[u].size();
	maxx=max(maxx,(int)g[u].size());
	for(auto v:g[u])
	{
		if(v==fax) continue;
		dfs(v,u);
		maxx=max(maxx,dp[u]+dp[v]-2);
		dp[u]=max(dp[u],dp[v]-2+(int)g[u].size());
	}
}
void solve()
{
	cin>>n;
	maxx=0;
	for(int i=0;i<=n+5;i++) g[i].clear(),dp[i]=0;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<maxx<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}