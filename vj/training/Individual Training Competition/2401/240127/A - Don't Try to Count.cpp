/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-27 21:29:04
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
	int n,m; cin>>n>>m;
	string x,s;
	cin>>x>>s;
	for(int i=0;i<=8;i++)
	{
		if(x.find(s)!=x.npos)
		{
			cout<<i<<endl;
			return;
		}
		x+=x;
	}
	cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}