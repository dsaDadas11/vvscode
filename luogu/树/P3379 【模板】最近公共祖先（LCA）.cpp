/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2025-02-25 19:57:24
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
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,s;
vector<int> g[N];
int dep[N];
int fa[N][20];
void dfs(int u,int fax)
{
    dep[u]=dep[fax]+1;
    fa[u][0]=fax;
    for(int j=1;j<20;j++)
    {
        fa[u][j]=fa[fa[u][j-1]][j-1];
    }
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int j=19;j>=0;j--)
    {
        if(dep[fa[x][j]]>=dep[y]) x=fa[x][j];
        if(x==y) return x;
    }
    for(int j=19;j>=0;j--)
    {
        if(fa[x][j]!=fa[y][j])
        {
            x=fa[x][j];
            y=fa[y][j];
        }
    }
    return fa[x][0];
}
void solve()
{
    cin>>n>>m>>s;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s,0);
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/