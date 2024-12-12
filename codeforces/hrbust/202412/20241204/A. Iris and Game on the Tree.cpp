/*
 * @Author: dsaDadas11
 * @Date: 2024-12-04 21:12:43
 * @LastEditTime: 2024-12-04 21:13:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s;
vector<int> g[N];
int stp;
int ans;
void dfs(int u,int fax)
{
	if(g[u].size()==1&&u!=1)
	{
		if(s[u]=='?')
		{
			if(stp&1) ans++;
			stp++;
		}
		else
		{
			if(s[1]=='0'&&s[u]=='1') ans++;
			else if(s[1]=='1'&&s[u]=='0') ans++;
		}
		return;
	}
	for(auto v:g[u])
	{
		if(v==fax) continue;
		dfs(v,u);
	}
}
int cnt; // 叶子节点问号个数
int cnt0,cnt1;
int ans0,ans1;
void dfs1(int u,int fax)
{
	if(g[u].size()==1&&u!=1)
	{
		if(s[u]=='1') cnt1++;
		else if(s[u]=='0') cnt0++;
		if(s[u]=='?')
		{
			cnt++;
		}
		else
		{
			if(s[u]=='1') ans1++;
			else ans0++;
		}
	}
	for(auto v:g[u])
	{
		if(v==fax) continue;
		dfs1(v,u);
	}
}
int sum; // 问号的总数
void dfs2(int u,int fax)
{
	for(auto v:g[u])
	{
		if(v==fax) continue;
		if(s[v]=='?') sum++;
		dfs2(v,u);
	}
}
void solve()
{
	cin>>n;
	for(int i=0;i<=n;i++) g[i].clear();
	int u,v;
	stp=1;
	ans=ans0=ans1=0;
	cnt=cnt0=cnt1=0;
	sum=0;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>s;
	s=' '+s;
	dfs2(1,0);
	if(s[1]=='?')
	{
		dfs1(1,0);
		if(cnt1==cnt0)
		{
			int sum1=sum-cnt;
			if(sum1&1)
			{
				cout<<cnt0+(cnt+1)/2<<endl;
			}
			else
			{
				cout<<cnt0+cnt/2<<endl;
			}
		}
		else if(cnt1>cnt0)
		{
			cout<<ans1+cnt/2<<endl;
		}
		else
		{
			cout<<ans0+cnt/2<<endl;
		}
	}
	else
	{
		dfs(1,0);
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}