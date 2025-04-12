/*
 * @Author: HuangCe
 * @Date: 2025-02-18 13:46:53
 * @LastEditTime: 2025-02-18 13:47:50
 * @Description: go for it!
 */
/*
 解题思路：
 用 lca解决树上差分问题，很板，但是没板子肯定做不出来 ^_^
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
struct Edge
{
    int v,w;
};
vector<Edge> g[N];

int fa[N][20],dep[N];
void dfs1(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=19;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i].v==f) continue;
		dfs1(g[x][i].v,x);
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

int dis[N];
void dfs2(int u,int fax)
{
    for(auto [v,w]:g[u])
    {
        if(v==fax) continue;
        dis[v]=dis[u]+w;
        dfs2(v,u);
    }
}

int calc(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    int lc=lca(u,v);
    if(lc==v) return dis[u]-dis[v];
    else return dis[v]+dis[u]-2*dis[lc];
}

void solve()
{
    cin>>n>>k;
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }

    dfs1(1,0);
    dfs2(1,0);

    int sumd=0;
    for(int i=1;i<k;i++)
    {
        sumd+=calc(a[i],a[i+1]);
    }

    for(int i=1;i<=k;i++)
    {
        int l,r,x;
        if(i==1) l=0;
        else l=calc(a[i-1],a[i]);

        if(i==k) r=0;
        else r=calc(a[i],a[i+1]);

        if(i==1||i==k) x=0;
        else x=calc(a[i-1],a[i+1]);

        cout<<sumd-l-r+x<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}