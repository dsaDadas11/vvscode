/*
 * @Author: dsaDadas11
 * @Date: 2024-04-09 13:18:27
 * @LastEditTime: 2024-04-09 13:35:49
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
	int n,k,d; // 写成double T爆了
	double x,ans;
	cin>>n>>k>>d;
	x=2.0*(k-1)*n/(2*k-2+sqrt(2));
	ans=1.0*d/(((n-x)/2)*((n-x)/2));
	cout<<fixed<<setprecision(8)<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}