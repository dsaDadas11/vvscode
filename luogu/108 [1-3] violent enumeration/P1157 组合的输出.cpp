/*
 * @Author: dsaDadas11
 * @Date: 2024-10-28 19:11:06
 * @LastEditTime: 2024-10-28 19:11:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,r;
int a[57];
bool vis[57];
void dfs(int x,int p)
{
	if(x==r+1)
	{
		for(int i=1;i<=r;i++)
		{
			cout<<setw(3)<<a[i];
		}
		cout<<endl;
		return;
	}
	for(int i=p;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		a[x]=i;
		dfs(x+1,i+1);
		vis[i]=0;
		a[x]=0;
	}
}
void solve()
{
	cin>>n>>r;
	dfs(1,1);
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}