/*
 * @Author: dsaDadas11
 * @Date: 2024-03-26 22:18:01
 * @LastEditTime: 2024-03-26 22:18:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n,m,x;
	cin>>n>>m>>x;
	int t,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t>=x) ans++;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		if(t<=x) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}