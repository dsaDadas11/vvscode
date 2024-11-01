/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-18 18:42:15
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,m,s;
int dep[N],fa[N][20];
vector<int> g[N];
void dfs(int x,int f)
{
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=19;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int to:g[x])
	{
		if(to==f) continue;
		dfs(to,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=19;i>=0;i--)
	{
		if(d&(1<<i))
		{
			x=fa[x][i];
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
	for(int i=1;i<n;i++)
	{
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(s,s);
	while(m--)
	{
		int a,b; cin>>a>>b;
		int ans=lca(a,b);
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}