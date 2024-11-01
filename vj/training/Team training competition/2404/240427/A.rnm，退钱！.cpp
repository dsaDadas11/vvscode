/*
 * @Author: dsaDadas11
 * @Date: 2024-04-28 19:51:54
 * @LastEditTime: 2024-04-28 19:52:01
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
	int n,sum=0,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
	}
	cout<<sum<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}