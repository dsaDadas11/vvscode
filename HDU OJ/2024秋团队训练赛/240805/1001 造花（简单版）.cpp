/*
 * @Author: dsaDadas11
 * @Date: 2024-08-07 11:20:27
 * @LastEditTime: 2024-08-07 11:20:32
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
int du[N],u[N],v[N];
int sz[N],du2[N],fa[N];
int findfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
void merge(int x,int y)
{
	int fax=findfa(x);
	int fay=findfa(y);
	fa[fax]=fay;
	du2[x]++,du2[y]++;
	sz[fay]+=sz[fax];
}
void solve()
{
	cin>>n;
	fill(du,du+1+n,0);
	for(int i=1;i<n;i++)
	{
		cin>>u[i]>>v[i];
		du[u[i]]++;
		du[v[i]]++;
	}
	if(n<=2)
	{
		cout<<"No"<<endl;
		return;
	}
	bool flag=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(du[i]!=2||cnt>=6) continue;
		cnt++;
		flag=1;
		fill(du2,du2+1+n,0);
		fill(sz,sz+1+n,1);
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<n;j++)
		{
			if(u[j]==i||v[j]==i) continue;
			merge(u[j],v[j]);
		}
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			if(du2[j]==1) sz[findfa(j)]--;
		}
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			if(findfa(j)==j&&sz[j]>1) flag=0;
		}
		if(flag) break;
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}