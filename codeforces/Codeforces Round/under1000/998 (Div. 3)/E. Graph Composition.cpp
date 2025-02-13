/*
 * @Author: dsaDadas11
 * @Date: 2025-01-20 00:22:36
 * @LastEditTime: 2025-01-20 00:22:55
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct DSU {
	vector<int> p;
	DSU(int n) {
		p.resize(n+1);
		iota(p.begin(), p.end(), 0);
	}
	int find(int x) {
		return p[x] == x ? x : p[x] = find(p[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x != y) p[y] = x;
	}
};
int n,m1,m2; 
pair<int,int> p[N];
void solve()
{
	cin>>n>>m1>>m2;
	DSU G(n), F(n);
	for(int i=1;i<=m1;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	for(int i=1;i<=m2;i++)
	{
		int u,v;
		cin>>u>>v;
		G.unite(u,v);
	}
	int res=0;
	for(int i=1;i<=m1;i++){
		int u=p[i].first;
		int v=p[i].second;
		if(G.find(u)!=G.find(v))
		{
			res++;
		}
		else
		{
			F.unite(u,v);
		}
	}
	int ans=0;
	map<int, set<int> > mp;
	for(int i=1;i<=n;i++){
		mp[G.find(i)].insert(F.find(i));
	}
	for(auto i:mp){
		ans+=(i.second.size()-1);
	}
	cout<<ans+res<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}