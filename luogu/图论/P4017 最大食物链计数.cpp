#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=80112002;
vector<int> g[N];
int ind[N],outd[N],num[N];
queue<int> q;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		ind[v]++;
		outd[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(ind[i]==0)
		{
			q.push(i);
			num[i]=1;
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<(int)g[x].size();i++)
		{
			int v=g[x][i];
			ind[v]--;
			num[v]=(num[v]+num[x])%M;
			if(ind[v]==0) q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(outd[i]==0)
		{
			ans=(ans+num[i])%M;
		}
	}
	cout<<ans<<endl;
	return 0;
}