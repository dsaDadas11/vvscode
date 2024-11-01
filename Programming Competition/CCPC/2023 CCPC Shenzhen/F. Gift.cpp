/*
 * @Author: dsaDadas11
 * @Date: 2024-10-17 10:56:41
 * @LastEditTime: 2024-10-17 11:05:55
 * @Description: go for it!
 */
/*
 解题思路：
 前置知识：基环树：有n个节点n条边的无向连通图
 要使删除边后为一颗树，那么一定是删除环上的边，删除后判断合不合法即可，
 1.根节点的度<=3 合法
 2.其他节点的度<=4 合法
 3.如果删完边后还有=5的度那么这颗树不合法
 4.我们只需要找 <=3 =4 =5 的度就行，因为题目保证了一定有解

 那么我们想想方案数：
 1.<=3 既能当根节点又能当其他节点
 2.=4 只能当其他节点，
 因此方案数肯定就是 <=3度数的点轮流当根节点的情况
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int d[N];
int fa[N],vis[N],dep[N];
vector<int> g[N];
pair<int,int> loop[N];
void find_loop(int u)
{
	dep[u]=dep[fa[u]]+1;
	for(auto v:g[u])
	{
		if(v==fa[u]) continue;
		if(!dep[v])
		{
			fa[v]=u;
			find_loop(v);
		}
		else if(dep[v]<dep[u])
		{
			loop[++m]={u,v};
			for(int i=u;;i=fa[i])
			{
				loop[++m]={i,fa[i]};
				vis[i]=1,vis[fa[i]]=1;
				if(fa[i]==v) break;
			}
		}
	}
}
int cnt3; // 度数小于等于3的节点
int cnt4; // 度数为4的节点
int cnt5; // 度数为5的节点
void solve()
{
	cin>>n;
	int u,v;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++,d[v]++;
	}
	find_loop(1);
	for(int i=1;i<=n;i++)
	{
		if(d[i]<=3) cnt3++;
		else if(d[i]==4) cnt4++;
		else if(d[i]==5) cnt5++;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		u=loop[i].first;
		v=loop[i].second;
		// 先删除再添加
		if(d[u]<=3) cnt3--;
		else if(d[u]==4) cnt4--;
		else if(d[u]==5) cnt5--;

		if(d[v]<=3) cnt3--;
		else if(d[v]==4) cnt4--;
		else if(d[v]==5) cnt5--;

		d[u]--,d[v]--;

		if(d[u]<=3) cnt3++;
		else if(d[u]==4) cnt4++;
		else if(d[u]==5) cnt5++;

		if(d[v]<=3) cnt3++;
		else if(d[v]==4) cnt4++;
		else if(d[v]==5) cnt5++;

		if(!cnt5) ans+=cnt3;

		// 返回原始状态
		if(d[u]<=3) cnt3--;
		else if(d[u]==4) cnt4--;
		else if(d[u]==5) cnt5--;

		if(d[v]<=3) cnt3--;
		else if(d[v]==4) cnt4--;
		else if(d[v]==5) cnt5--;

		d[u]++,d[v]++;

		if(d[u]<=3) cnt3++;
		else if(d[u]==4) cnt4++;
		else if(d[u]==5) cnt5++;

		if(d[v]<=3) cnt3++;
		else if(d[v]==4) cnt4++;
		else if(d[v]==5) cnt5++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}