/*
 * @Author: dsaDadas11
 * @Date: 2024-04-18 20:36:17
 * @LastEditTime: 2024-04-18 20:36:23
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
	int m,k,a1,ak;
	cin>>m>>k>>a1>>ak;
	int x=m/k;
	int y=m%k;
	if(ak>=x)
	{
		if(a1>=y)
		{
			cout<<'0'<<endl;
		}
		else
		{
			cout<<y-a1<<endl;
		}
	}
	else
	{
		if(a1>=y)
		{
			a1-=y;
			x-=(a1/k);
			cout<<max(0LL,x-ak)<<endl;
		}
		else
		{
			cout<<x-ak+y-a1<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}