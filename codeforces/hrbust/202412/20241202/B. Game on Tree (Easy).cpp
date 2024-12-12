/*
 * @Author: dsaDadas11
 * @Date: 2024-12-02 18:39:08
 * @LastEditTime: 2024-12-02 18:39:13
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,t;
vector<int> g[N];
// 记录 Ron
bool dfs(int u,int fax,int stp)
{
	if(g[u].size()==1)
	{
		if(stp&1) return 1;
		return 0;
	}
	bool flag=0;
	for(auto v:g[u])
	{
		if(v==fax) continue;
		if(dfs(v,u,stp+1))
		{
			flag=1;
			break;
		}
	}
	//cout<<"u: "<<u<<"   stp: "<<stp<<endl;
	if(flag) return 1;
	return 0;
}
void solve()
{
	cin>>n>>t;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int p;
	cin>>p;
	if(dfs(p,0,0)) cout<<"Ron"<<endl;
	else cout<<"Hermione"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}