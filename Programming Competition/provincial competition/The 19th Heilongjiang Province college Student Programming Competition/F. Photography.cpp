/*
 * @Author: dsaDadas11
 * @Date: 2024-05-14 20:00:36
 * @LastEditTime: 2024-05-14 20:02:58
 * @Description: go for it!
 */
/*
解题思路：
1.不用dfs，用for循环遍历五个点 (dfs不好维护每个点)
2.遍历的时候判断是否会走到父节点
比赛时候真想不出来aaaa
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e3+7;
constexpr int M=2e3+7;
int a[N];
vector<int> g[N];
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
void solve()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		sort(g[i].begin(),g[i].end(),cmp);
	}
	int ans=0;
	for(int u=1;u<=n;u++)
	{
		ans=max(ans,a[u]);
		for(int v:g[u])
		{
			if(v!=u)
			{
				ans=max(ans,a[u]+a[v]);
				for(int w:g[v])
				{
					if(w!=u&&w!=v)
					{
						ans=max(ans,a[u]+a[v]+a[w]);
						int x=0,y=0;
						for(int k:g[u])
						{
							if(k!=u&&k!=v&&k!=w)
							{
								x=k;
								break;
							}
						}
						for(int k:g[w])
						{
							if(k!=u&&k!=v&&k!=w&&k!=x)
							{
								y=k;
								break;
							}
						}
						ans=max(ans,a[u]+a[v]+a[w]+a[x]+a[y]);
					}
				}
			}
		}
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