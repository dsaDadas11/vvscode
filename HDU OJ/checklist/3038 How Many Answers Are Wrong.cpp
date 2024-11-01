/*
 * @Author: dsaDadas11
 * @Date: 2024-08-27 21:08:04
 * @LastEditTime: 2024-08-27 21:08:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
int ans;
int fa[N];
int d[N]; // x到父节点的距离
int findfa(int x)
{
	if(fa[x]!=x)
	{
		int t=fa[x];
		fa[x]=findfa(fa[x]);
		d[x]+=d[t];
	}
	return fa[x];
}
void merge(int a,int b,int val)
{
	int roota=findfa(a);
	int rootb=findfa(b);
	if(roota==rootb)
	{
		if(d[a]-d[b]!=val) ans++;
	}
	else
	{
		fa[roota]=rootb;
		d[roota]=d[b]-d[a]+val;
	}
}
void solve()
{
	while(cin>>n>>m)
	{
		ans=0;
		// 初始化fa和d
		for(int i=0;i<N;i++)
		{
			fa[i]=i;
			d[i]=0;
		}
		int a,b,val;
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b>>val;
			a--;
			merge(a,b,val);
		}
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}