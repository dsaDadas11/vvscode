/*
 * @Author: HuangCe
 * @Date: 2025-02-19 19:06:47
 * @LastEditTime: 2025-02-19 19:23:33
 * @Description: go for it!
 */
/*
 解题思路：
 这题居然能用 pow过...pow 700ms 、long double 900ms 、 quickpow 500ms
 这是一道树形概率 dp，显而易见我又想不出来
 首先设 dp[u]为 u节点到根节点的期望, u是 v的父节点
 假设在 u->root上有 u1 u2 跳板
 那么有状态转移方程 dp[u] = (1-p)*(dp[u1]+1) + p*(1 + (1-p)*(dp[u2]+1) + p*(1 + dist))
 若 u也为跳板，那么 v可以直接走到 u(跳或不跳结局一样,那就不跳) 即 dp[v] = dp[u] + 1
 否则 dp[v] = (1-p)*(dp[u1]+1) + p*(1 + (1-p)*(dp[u2]+1) + p*(1 + (dist + 1)))
 可以发现，v节点要多走 1距离的路，将 1提出括号，就转换成了
 dp[v] = (1-p)*(dp[u1]+1) + p*(1 + (1-p)*(dp[u2]+1) + p*(1 + dist)) + p^2
 也就是 dp[v] = dp[u] + p^cnt (cnt为 u到根节点路径上的跳板个数)
 
 综上：
 if(a[u]) dp[v]=dp[u]+1;
 else dp[v]=dp[u]+pow(p,cnt);
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
double p;
vector<int> g[N];
double dp[N];
bool a[N];
int cnt;
double quickpow(double x,int y)
{
    double ans=1.0;
    while(y)
    {
        if(y&1) ans*=x;
        x*=x;
        y>>=1;
    }
    return ans;
}
void dfs(int u,int fa)
{
	if(a[u]) cnt++;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		if(a[u]) dp[v]=dp[u]+1;
		else dp[v]=dp[u]+quickpow(p,cnt);
		dfs(v,u);
	}
	if(a[u]) cnt--;
}
void solve()
{
	cout<<fixed<<setprecision(2);
	
	cin>>n>>m>>p;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u;
		a[u]=1;
	}
	dfs(1,0);
	double sum=accumulate(dp+1,dp+1+n,0.0);
	cout<<sum/n+1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}