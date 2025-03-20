/*
 * @Author: dsaDadas11
 * @Date: 2024-08-19 18:15:22
 * @LastEditTime: 2024-08-19 18:15:28
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
void solve()
{
	cin>>n>>k;
	if(n==k)
	{
		cout<<"A";
		return;
	}
	if(k==1)
	{
		if(n%2) cout<<"A";
		else cout<<"B";
		return;
	}
	cout<<"B";
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}