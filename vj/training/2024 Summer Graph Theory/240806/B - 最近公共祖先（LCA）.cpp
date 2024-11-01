/*
 * @Author: dsaDadas11
 * @Date: 2024-08-06 14:24:37
 * @LastEditTime: 2024-08-06 14:24:46
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int N=1e6+7;
int n,m,s;
vector<int> g[N];
int fa[N][20],dep[N];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=19;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]==f) continue;
		dfs(g[x][i],x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=19;i>=0;i--)
	{
		if(d>=(1<<i))
		{
			x=fa[x][i];
			d-=(1<<i);
		}
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void solve()
{
	cin>>n>>m>>s;
	int u,v,a,b;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(s,s);
	while(m--)
	{
		cin>>a>>b;
		cout<<lca(a,b)<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}