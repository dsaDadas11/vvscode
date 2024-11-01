/*
 * @Author: dsaDadas11
 * @Date: 2024-03-31 22:25:30
 * @LastEditTime: 2024-03-31 22:25:36
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
void solve()
{
	int k;
	cin>>k;
	int ans=1;
	for(int i=1;i<=k-1;i++)
	{
		ans=(ans*2)%mod;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}