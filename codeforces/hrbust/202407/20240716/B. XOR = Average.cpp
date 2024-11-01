/*
 * @Author: dsaDadas11
 * @Date: 2024-07-17 09:36:18
 * @LastEditTime: 2024-07-17 10:51:32
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
	int n;
	cin>>n;
	if(n%2)
	{
		for(int i=1;i<=n;i++) cout<<"1 ";
		cout<<endl;
	}
	else
	{
		cout<<"2 6 ";
		for(int i=1;i<=n-2;i++)
		{
			cout<<"4 ";
		}
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}