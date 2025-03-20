/*
 * @Author: dsaDadas11
 * @Date: 2025-03-16 20:50:43
 * @LastEditTime: 2025-03-16 20:50:54
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
int sz[N],w[N];
int fa[N];
vector<int> g[N];
set<pair<int,int>> se[N];
void dfs(int u,int fax)
{
	fa[u]=fax;
	sz[u]=1,w[u]=a[u];
	for(auto v:g[u])
	{
		if(v==fax) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		w[u]+=w[v];
		se[u].insert({sz[v],-v});
	}
}
void solve()
{
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1,0);
	
	int t,x;
	for(int i=1;i<=m;i++)
	{
		cin>>t>>x;
		if(t==1)
		{
			cout<<w[x]<<endl;
		}
		else
		{
			if(se[x].empty()) continue;
			
			int fau=fa[x],sonv=-(se[x].rbegin()->second);
			
			se[fau].erase({sz[x],-x});
			se[x].erase({sz[sonv],-sonv});
			
			sz[x]-=sz[sonv],sz[sonv]+=sz[x];
			w[x]-=w[sonv],w[sonv]+=w[x];
			
			se[fau].insert({sz[sonv],-sonv});
			se[sonv].insert({sz[x],-x});
			
			fa[x]=sonv;
			fa[sonv]=fau;
			
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}