/*
 * @Author: dsaDadas11
 * @Date: 2024-08-13 14:37:17
 * @LastEditTime: 2024-08-13 14:37:29
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
	cin>>n;
	long double ans=0.0;
	for(int i=n;i>=1;i--)
	{
		ans+=(long double)((long double)1.0/i);
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}