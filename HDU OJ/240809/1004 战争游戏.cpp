/*
 * @Author: dsaDadas11
 * @Date: 2024-08-11 20:51:00
 * @LastEditTime: 2024-08-11 21:30:22
 * @Description: go for it!
 */
/*
 做两次dfs：
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,s,r1,r2;
int u,v;
vector<int> g[N];
int dist[N];
void dfs(int u,int fa)
{
	dist[u]=dist[fa]+1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n>>s>>r1>>r2;
	for(int i=0;i<=n;i++) g[i].clear();
	memset(dist,0,sizeof dist);
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int idx=1;
	for(int i=2;i<=n;i++)
	{
		if(dist[i]>dist[idx])
		{
			idx=i;
		}
	}
	dfs(idx,0);
	int d=0;
	for(int i=1;i<=n;i++)
	{
		d=max(d,dist[i]);
	}
	if(2*r1+1>=d)
	{
		cout<<"Kangaroo_Splay"<<endl;
		return;
	}
	if(r1*2>=r2) cout<<"Kangaroo_Splay"<<endl;
	else cout<<"General_Kangaroo"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 树形dp写法：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,ans;
int s,r1,r2;
int u,v;
vector<int> g[N];
bool vis[N];
int dfs(int u)
{
	vis[u]=1;
	int d1=0,d2=0; //从u点往下走的最大和次大长度
	for(auto v:g[u])
	{
		if(vis[v]) continue;
		int d=dfs(v)+1;
		if(d>=d1) d2=d1,d1=d;//更新最大和次大长度
		else if(d>d2) d2=d;
	}
	ans=max(ans,d1+d2+1); //更新答案(以u为中心的最长路径:d1+d2)
	return d1; //返回从u点往下走的最大长度
}
void solve()
{
	cin>>n>>s>>r1>>r2;
	ans=0;
	for(int i=0;i<=n;i++) g[i].clear();
	memset(vis,0,sizeof vis);
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1); //可任取一点
	if(2*r1+1>=ans)
	{
		cout<<"Kangaroo_Splay"<<endl;
		return;
	}
	if(r1*2>=r2) cout<<"Kangaroo_Splay"<<endl;
	else cout<<"General_Kangaroo"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/