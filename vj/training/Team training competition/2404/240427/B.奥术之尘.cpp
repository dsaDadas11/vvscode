/*
 * @Author: dsaDadas11
 * @Date: 2024-04-28 19:55:16
 * @LastEditTime: 2024-04-28 19:55:22
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],b[N];
void solve()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+1+m);
	for(int i=1;i<=m;i++)
	{
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int pos=upper_bound(b+1,b+1+m,a[i])-b-1;
		cout<<pos<<' ';
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