/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2025-09-03 20:04:16
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


/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n,m,s;
vector<int> g[N];
int fa[N],son[N],sz[N],dep[N],top[N];
// 父节点，重儿子，子树大小，深度，链头节点
void dfs1(int u,int fax) // 初始化 fa,dep,son
{
    dep[u]=dep[fax]+1;
    fa[u]=fax,sz[u]=1;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) // 求各节点的 top数组
{
    top[u]=t; // 记录链头
    if(!son[u]) return; // 无重儿子返回
    dfs2(son[u],t); // 搜重儿子
    for(auto v:g[u])
    {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v); // 搜轻儿子
    }
}
int lca(int u,int v)
{
    while(top[u]!=top[v]) // 让 u,v跳到一条链上
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v); // 保证 u的深度最大
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
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
    dfs1(s,0);
    dfs2(s,0);
    while(m--)
    {
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
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
int f[N][20],lg[N];
int dfn[N],cur;
void dfs(int u,int fax)
{
    dfn[u]=++cur;
    f[dfn[u]][0]=fax;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
    }
}
void init()
{
    lg[1]=0;
    for(int i=2;i<N;i++)
    {
        lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
    }
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    int k=lg[v-u++]; // 没有加 1

    int x=f[u][k],y=f[v-(1<<k)+1][k];
    if(dfn[x]<dfn[y]) return x;
    else return y; 
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

    for(int j=1;j<20;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            int x=f[i][j-1],y=f[i+(1<<(j-1))][j-1];
            if(dfn[x]<dfn[y]) f[i][j]=x;
            else f[i][j]=y;
        }
    }

    while(m--)
    {
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/