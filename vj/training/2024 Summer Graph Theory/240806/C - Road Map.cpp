/*
 * @Author: dsaDadas11
 * @Date: 2024-08-06 14:36:53
 * @LastEditTime: 2024-08-06 14:44:07
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,r1,r2;
vector<int> g[N];
int a[N],ans[N];
bool vis[N];
queue<int> q;
void solve()
{
	cin>>n>>r1>>r2;
	for(int i=1;i<n;i++) cin>>a[i];
	int idx=1;
	for(int i=1;i<=n;i++)
	{
		if(i==r1) continue;
		g[a[idx]].push_back(i);
		g[i].push_back(a[idx]);
		idx++;
	}
	q.push(r2);
	vis[r2]=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(auto it:g[t])
		{
			if(vis[it]) continue;
			vis[it]=1;
			ans[it]=t;
			q.push(it);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==r2) continue;
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
