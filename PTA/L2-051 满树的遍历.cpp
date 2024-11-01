/*
 * @Author: dsaDadas11
 * @Date: 2024-04-23 19:29:32
 * @LastEditTime: 2024-04-23 19:31:36
 * @Description: go for it!
 */
// 这道题的度指的是出度
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
vector<int> g[N];
int ind[N],outd[N];
bool vis;
void dfs(int x)
{
	if(!vis) cout<<x;
	else cout<<' '<<x;
	vis=1;
	for(int i=0;i<(int)g[x].size();i++)
	{
		int u=g[x][i];
		dfs(u);
	}
}
void solve()
{
	int n,x,rt;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x!=0)
		{
			g[x].push_back(i);
			outd[x]++;
			ind[i]++;
		}
		else rt=i;
	}
	int du=0;
	for(int i=1;i<=n;i++)
	{
		if(outd[i]==0) continue;
		du=max(du,outd[i]);
	}
	cout<<du;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		if(outd[i]==0) continue;
		if(du!=outd[i])
		{
			flag=0;
			break;
		}
	}
	if(flag) cout<<" yes"<<endl;
	else cout<<" no"<<endl;
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==0) continue;
		sort(g[i].begin(),g[i].end());
	}
	dfs(rt);
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}