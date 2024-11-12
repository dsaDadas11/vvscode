/*
 * @Author: dsaDadas11
 * @Date: 2024-11-08 21:38:31
 * @LastEditTime: 2024-11-08 22:00:04
 * @Description: go for it!
 */
/*
 解题思路：
 题意：有些点能走一次，有些点能走两次，求x是否能走到y并走回x
 注意：x要走两次，y只需要走一次，因此处理x和fa[y]就行
 很容易想到我们要预处理出一个节点到另一个节点的次数和路径中的节点数 (有点像前缀和和差分)，
 这里我愣了楞
 直接预处理每个节点到根节点的次数即可，然后求lca，画图找规律可以发现
 dx=d[x]-d[lc]+d[fa[y]]-d[lc]+cnt[lc]  d为该节点到根节点的次数
 rtc=dep[x]-dep[lc]+dep[fa[y]]-dep[lc]+1  dep为该节点深度
 然后判断dx是否等于rtc*2就可以

 启发：树上的预处理就处理该节点到根节点即可，然后求lca
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
vector<int> g[N];
int dep[N],f[N][20]; // 求lca
void dfs1(int x,int fx)
{
	dep[x]=dep[fx]+1;
	f[x][0]=fx;
	for(int i=1;i<=19;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]==fx) continue;
		dfs1(g[x][i],x);
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
			x=f[x][i];
			d-=(1<<i);
		}
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int cnt[N];
int d[N]; // 存该节点到根节点的能走的次数和
// dep存深度
int fa[N]; // 存父节点
void dfs(int u,int fx)
{
	fa[u]=fx;
	d[u]=d[fa[u]]+cnt[u];
	for(auto v:g[u])
	{
		if(v==fx) continue;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=n+5;i++)
	{
		cnt[i]=fa[i]=dep[i]=d[i]=0;
		g[i].clear();
		for(int j=0;j<=19;j++) f[i][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>cnt[i];
	}
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	dfs(1,0);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		int lc=lca(x,y);
		int dx=d[x]-d[lc]+d[fa[y]]-d[lc]+cnt[lc];
		int rtc=dep[x]-dep[lc]+dep[fa[y]]-dep[lc]+1;
		if(dx==rtc*2) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}