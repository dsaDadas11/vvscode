#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int fa[N];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		int x=find(a);
		int y=find(b);
		fa[x]=y;
	}
	for(int i=1;i<=p;i++)
	{
		int a,b;
		cin>>a>>b;
		int x=find(a);
		int y=find(b);
		if(x==y) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}