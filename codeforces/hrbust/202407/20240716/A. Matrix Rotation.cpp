/*
 * @Author: dsaDadas11
 * @Date: 2024-07-17 09:16:00
 * @LastEditTime: 2024-07-17 10:51:18
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[4][4];
bool check()
{
	if(a[1][1]<a[1][2]&&a[1][1]<a[2][1]&&a[2][1]<a[2][2]&&a[1][2]<a[2][2]) return 1;
	return 0;
}
void sp()
{
	swap(a[1][1],a[1][2]);
	swap(a[1][1],a[2][2]);
	swap(a[1][1],a[2][1]);
}
void solve()
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(check())
		{
			cout<<"YES"<<endl;
			return;
		}
		sp();
	}
	cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}