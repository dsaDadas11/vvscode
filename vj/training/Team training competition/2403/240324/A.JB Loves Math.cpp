/*
 * @Author: dsaDadas11
 * @Date: 2024-03-26 21:16:13
 * @LastEditTime: 2024-03-26 21:16:19
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
	int a,b;
	cin>>a>>b;
	int d=abs(a-b);
	if(a<b)
	{
		if(d%2) cout<<1<<endl;
		else
		{
			d/=2;
			if(d%2) cout<<2<<endl;
			else cout<<3<<endl;
		}
	}
	else if(a>b)
	{
		if(d%2) cout<<2<<endl;
		else cout<<1<<endl;
	}
	else cout<<0<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}