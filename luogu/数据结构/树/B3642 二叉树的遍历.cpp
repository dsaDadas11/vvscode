/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-04-20 22:13:57
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l[N],r[N];
int n;
void dfs1(int x)
{
	cout<<x<<' ';
	if(l[x]) dfs1(l[x]);
	if(r[x]) dfs1(r[x]);
}
void dfs2(int x)
{
	if(l[x]) dfs2(l[x]);
	cout<<x<<' ';
	if(r[x]) dfs2(r[x]);
}
void dfs3(int x)
{
	if(l[x]) dfs3(l[x]);
	if(r[x]) dfs3(r[x]);
	cout<<x<<' ';
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	dfs1(1);
	cout<<endl;
	dfs2(1);
	cout<<endl;
	dfs3(1);
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}