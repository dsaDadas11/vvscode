/*
 * @Author: dsaDadas11
 * @Date: 2024-04-09 14:00:53
 * @LastEditTime: 2024-04-09 14:00:58
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
int a[17];
int ans,sum;
void dfs2(int x)
{
	if(x==n+1)
	{
		sum++;
		if(a[n]==n) ans++;
		return;
	}
	if(a[x]==0)
	{
		a[x]=x;
		dfs2(x+1);
		a[x]=0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				a[i]=x;
				dfs2(x+1);
				a[i]=0;
			}
		}
	}
}
void dfs1(int x)
{
	if(x==m+1)
	{
		dfs2(m+1);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=x;
			dfs1(x+1);
			a[i]=0;
		}
	}
}
void solve()
{
	cin>>n>>m;
	dfs1(1);
	cout<<fixed<<setprecision(12)<<1.0*ans/sum<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}