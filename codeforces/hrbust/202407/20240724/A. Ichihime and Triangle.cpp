/*
 * @Author: dsaDadas11
 * @Date: 2024-07-24 14:50:33
 * @LastEditTime: 2024-07-24 20:16:51
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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=b,y=c;
	for(int i=c;i<=d;i++)
	{
		if(x+y>i&&abs(x-y)<i&&x+i>y&&abs(x-i)<y&&i+y>x&&abs(y-i)<x)
		{
			cout<<x<<' '<<y<<' '<<i<<endl;
			return;
		}
	}
	/* 更简便答案
	cout<<b<<' '<<c<<' '<<c<<endl;
	*/
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}