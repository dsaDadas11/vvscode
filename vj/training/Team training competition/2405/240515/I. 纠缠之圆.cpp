/*
 * @Author: dsaDadas11
 * @Date: 2024-05-15 20:04:04
 * @LastEditTime: 2024-05-15 20:04:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x1,x2,y11,y2,r1,r2;
long double d;
void solve()
{
	cin>>x1>>y11>>r1;
	cin>>x2>>y2>>r2;
	d=1.0*sqrt((x1-x2)*(x1-x2)+(y11-y2)*(y11-y2));
	if(d==0)
	{
		if(r1==r2)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}
	}
	else
	{
		if(d<r1+r2)
		{
			if(d>abs(r1-r2)) cout<<"2"<<endl;
			else if(d==abs(r1-r2)) cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
		else if(d==r1+r2)
		{
			cout<<"3"<<endl;
		}
		else cout<<"4"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}