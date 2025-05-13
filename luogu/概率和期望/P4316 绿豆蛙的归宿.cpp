/*
* @Author: dsaDadas11
* @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-11-11 19:26:13
* @Description: go for it!
*/
/*
 解题思路：
 转移一般是递推，通常分两种，一种是从上一个状态转移得（填表法），另一种是转移向下一个状态（刷表法）。
 有时期望dp需以最终状态为初始状态转移，即逆推。
 如f[i]表示期望还要走f[i]步到达终点。这种状态的转移是刷表法
 形如
 f[i] = ∑p[j→i]∗(f[j]+w[j→i])，其中p表示转移的概率，w表示转移对答案的贡献。
 一般来说，初始状态确定时可用顺推，终止状态确定时可用逆推。

 这道题我们采逆推，因为每个点需要前驱节点已知的期望进行转移，
 但前驱节点的状态未知(不能采用递推)，此时可以用dfs转到前驱节点，但是因为转移需要拓扑序，所以不能用dfs进行转移，
 那么我们就逆着来，从最终状态推到初始状态，采用拓扑排序
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
int d[N]; // 记录入度
int deg[N];
long double dp[N]; // i到n的期望
struct Edge
{
	int v,w;
};
vector<Edge> g[N];
queue<int> q;
void bfs()
{
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto [v,w]:g[u])
		{
			dp[v]+=(dp[u]+w)/deg[v];
			d[v]--;
			if(d[v]==0) q.push(v);
		}
	}
}
void solve()
{
	cin>>n>>m;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		// 建反图
		cin>>v>>u>>w;
		g[u].push_back({v,w});
		d[v]++,deg[v]++;
	}
	bfs();
	cout<<fixed<<setprecision(2)<<dp[1]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}