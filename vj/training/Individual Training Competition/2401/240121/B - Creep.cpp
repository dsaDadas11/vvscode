/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-21 21:00:37
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
	int a,b; cin>>a>>b;
	if(a>b)
	{
		for(int i=1;i<=b;i++)
		{
			cout<<"01";
		}
		for(int i=1;i<=a-b;i++)
		{
			cout<<"0";
		}
	}
	else
	{
		for(int i=1;i<=a;i++)
		{
			cout<<"10";
		}
		for(int i=1;i<=b-a;i++)
		{
			cout<<"1";
		}
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}