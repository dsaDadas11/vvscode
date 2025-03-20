/*
 * @Author: dsaDadas11
 * @Date: 2025-03-16 21:11:14
 * @LastEditTime: 2025-03-16 21:11:24
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,ans;
int dep[N],sum[N],d[N];
vector<int> g[N];
int stk[N],p;
void dfs(int u,int fax)
{
	dep[u]=dep[fax]+1;
	d[dep[u]]++;
	for(auto v:g[u])
	{
		if(v==fax) continue;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		while(p&&d[stk[p]]>=d[i]) p--;
		stk[++p]=i;
		sum[stk[p]]=sum[stk[p-1]]+d[stk[p]]*(stk[p]-stk[p-1]);
		ans=max(ans,sum[stk[p]]);
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