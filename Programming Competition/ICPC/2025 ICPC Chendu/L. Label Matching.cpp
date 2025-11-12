/*
 * @Author: dsaDadas11
 * @Date: 2025-10-29 21:35:37
 * @LastEditTime: 2025-10-29 21:35:45
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;

struct op
{
	map<int,int> td;
	int tot;
	int a0;
	int b0;
	
	op(){tot=0;a0=0;b0=0;}
};

int n;
int a[N],b[N];
int son[N],sz[N];
bool ans[N];
vector<int> g[N];
void dfs1(int u,int fax)
{
	sz[u]=1;
	for(int v:g[u])
	{
		if(v==fax) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void add(int u,int fax,int s,op &mat)
{
	if(a[u]==0) mat.a0++;
	else{
		int x=a[u];
		auto it=mat.td.find(x);
		int old=(it!=mat.td.end())?it->second:0;
		mat.tot-=max(0,old);
		int newd=old-1;
		mat.tot+=max(0,newd);
		if(newd!=0) mat.td[x]=newd;
		else if(it!=mat.td.end()) mat.td.erase(it);
	}
	if(b[u]==0) mat.b0++;
	else{
		int x=b[u];
		auto it=mat.td.find(x);
		int old=(it!=mat.td.end())?it->second:0;
		mat.tot-=max(0,old);
		int newd=old+1;
		mat.tot+=max(0,newd);
		if(newd!=0) mat.td[x]=newd;
		else if(it!=mat.td.end()) mat.td.erase(it);
	}
	
	for(int v:g[u])
	{
		if(v==fax||v==s) continue;
		add(v,u,s,mat);
	}
}
void sub(int u,int fax,op &mat)
{
	if(a[u]==0) mat.a0--;
	else{
		int x=a[u];
		auto it=mat.td.find(x);
		int old=(it!=mat.td.end())?it->second:0;
		mat.tot-=max(0,old);
		int newd=old+1;
		mat.tot+=max(0,newd);
		if(newd!=0) mat.td[x]=newd;
		else if(it!=mat.td.end()) mat.td.erase(it);
	}
	if(b[u]==0) mat.b0--;
	else{
		int x=b[u];
		auto it=mat.td.find(x);
		int old=(it!=mat.td.end())?it->second:0;
		mat.tot-=max(0,old);
		int newd=old-1;
		mat.tot+=max(0,newd);
		if(newd!=0) mat.td[x]=newd;
		else if(it!=mat.td.end()) mat.td.erase(it);
	}
	
	for(int v:g[u])
	{
		if(v==fax) continue;
		sub(v,u,mat);
	}
}
void dfs2(int u,int fax,bool lig,op &mat)
{
	for(int v:g[u])
	{
		if(v==fax||v==son[u]) continue;
		dfs2(v,u,1,mat);
	}
	if(son[u]) dfs2(son[u],u,0,mat);
	
	add(u,fax,son[u],mat);
	
	ans[u]=(mat.tot<=mat.a0);
	
	if(lig)
	{
		sub(u,fax,mat);
	}
	
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		son[i]=0;
		ans[i]=0;
	}
	
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	op mat;
	dfs1(1,0);
	dfs2(1,0,0,mat);
	
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i];
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}