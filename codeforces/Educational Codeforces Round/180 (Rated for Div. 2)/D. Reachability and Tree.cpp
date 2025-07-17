/*
 * @Author: dsaDadas11
 * @Date: 2025-07-17 18:47:11
 * @LastEditTime: 2025-07-17 18:48:30
 * @Description: go for it!
 */
/*
 解题思路：
 找度数为 2的点真是神来之笔，只要把度数为 2的两条边设为相反即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,pos;
vector<int> g[N];
int d[N];
vector<pair<int,int> > ans;
void dfs(int u,int fax,bool ok)
{
	for(auto v:g[u])
	{
		if(v==fax) continue;
		if(pos==u)
		{
			if(ok) ans.push_back({v,u});
			else ans.push_back({u,v});
			dfs(v,u,ok);
			pos=-1;
		}
		else
		{
			if(ok) ans.push_back({u,v});
			else ans.push_back({v,u});
			dfs(v,u,!ok);
		}
	}
}
void solve()
{
	cin>>n;
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        d[i]=0;
    }
    ans.clear();
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++,d[v]++;
	}
	pos=-1;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==2)
		{
			pos=i;
			break;
		}
	}
	if(pos==-1)
	{
		cout<<"NO"<<endl;
		return;
	}
	
	cout<<"YES"<<endl;
	dfs(1,0,1);
	for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
	
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}