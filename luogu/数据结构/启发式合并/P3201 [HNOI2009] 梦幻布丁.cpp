/*
 * @Author: dsaDadas11
 * @Date: 2025-09-03 20:33:11
 * @LastEditTime: 2025-09-03 20:33:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int col[N];
int now[N]; // 当前颜色为另一个颜色
vector<int> g[N];
int ans;
void merge_set(int x,int y)
{
	// x -> y  小的融合进大的
	for(auto i:g[x])
	{
		if(col[i+1]==y) ans--;
		if(col[i-1]==y) ans--;
	}
	for(auto i:g[x])
	{
		col[i]=y;
		g[y].push_back(i);
	}
	g[x].clear();
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>col[i];
		if(col[i]!=col[i-1]) ans++;
		now[col[i]]=col[i];
		g[col[i]].push_back(i);
	}

	int op,x,y;
	while(m--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			if(x==y) continue;

			if(g[now[x]].size()>g[now[y]].size()) swap(now[x],now[y]);
			x=now[x],y=now[y];
			if(g[x].size()!=0) merge_set(x,y);
		}
		else
		{
			cout<<ans<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}