/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-21 21:01:16
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[57];
void solve()
{
	int n; cin>>n;
	int x=INT_MAX,xi=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(x>a[i]) x=a[i],xi=i;
	}
	if(n%2)
	{
		cout<<"Mike"<<endl;
	}
	else
	{
		if(xi%2) cout<<"Joe"<<endl;
		else cout<<"Mike"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}