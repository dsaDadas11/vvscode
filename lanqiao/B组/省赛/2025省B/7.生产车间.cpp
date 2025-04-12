/*
 * @Author: dsaDadas11
 * @Date: 2025-04-12 20:31:36
 * @LastEditTime: 2025-04-12 20:33:35
 * @Description: go for it!
 */
/*
 解题思路：
 树上背包
 设 dp[u][j]为 u节点能存储 j的价值
 要通过 u的子树 v来更新 dp[u][j]的值，不然会重复子树贡献
 核心代码：
 
for(auto v:g[u])
{
    if(v==fax) continue;
    for(int j=w[u];j>=0;j--)
    {
        for(int k=w[v];k>=0;k--)
        {
            if(j+k<=w[u]) dp[u][j+k]|=dp[u][j]&dp[v][k];
        }
    }
}
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n;
int w[M];
bool dp[M][M];
vector<int> g[M];
void dfs(int u,int fax)
{
	dp[u][0]=1;
	if(g[u].size()==1&&u!=1) //如果 1也是叶子节点的话就不能为 1了
	{
		dp[u][w[u]]=1;
		return;
	}
	for(auto v:g[u])
	{
		if(v==fax) continue;
		dfs(v,u);
	}
	for(auto v:g[u])
    {
        if(v==fax) continue;
        for(int j=w[u];j>=0;j--)
        {
            for(int k=w[v];k>=0;k--)
            {
                if(j+k<=w[u]) dp[u][j+k]|=dp[u][j]&dp[v][k];
            }
        }
    }
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int ans=0;
	for(int j=0;j<=w[1];j++)
	{
		if(dp[1][j]) ans=j;
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