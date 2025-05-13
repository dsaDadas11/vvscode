/*
 * @Author: dsaDadas11
 * @Date: 2024-10-16 21:56:52
 * @LastEditTime: 2024-10-16 22:07:15
 * @Description: go for it!
 */
/*
 解题思路：
 基环树模板题 (有n个顶点,n条边的无向连通图)
 题目大意是：在A,B两点放两颗棋子,每次两人同时操作棋子沿图边移动一步,若两棋子同时走到了同一个点上或者同时走过了相同的边,则B胜利,否则A胜利
 我们先找环，将环上的点编号(以路径大小排序)，然后都存起来，第二次以环上的点往树上做dfs找每个点到该环点的最短路径，并标出属于哪个环点，
 最后从一个环点到另一个环点的路径就是编号相减，或者环的总路径-编号相减
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q,m;
vector<int> g[N];
int dep[N],fa[N],vis[N];
int loop[N],top[N];
void find_loop(int u)
{
	dep[u]=dep[fa[u]]+1;
	for(auto v:g[u])
	{
		if(v==fa[u]) continue;
		if(!dep[v]) // 还没遍历到这点
		{
			fa[v]=u;
			find_loop(v);
		}
		else if(dep[v]<dep[u]) // 深度比父节点小，肯定有环，并且环开头是在v
		{
			for(int i=u;;i=fa[i])
			{
				loop[++m]=i;
				vis[i]=1;
				if(i==v) break;
			}
		}
	}
}
void dfs(int u,int fax,int tp)
{
	top[u]=tp;
	for(auto v:g[u])
	{
		if(v==fax||vis[v]) continue;
		dep[v]=dep[u]+1;
		dfs(v,u,tp);
	}
}
void solve()
{
	cin>>n>>q;
	int u,v;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	find_loop(1);
	for(int i=0;i<=n+5;i++) dep[i]=0;
	for(int i=1;i<=m;i++)
	{
		// 环的节点编号从 1-m
		dfs(loop[i],0,i);
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(dep[y]+min(abs(top[x]-top[y]),m-abs(top[x]-top[y]))<=dep[x])
		{
			cout<<"Deception"<<endl;
		}
		else cout<<"Survive"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}