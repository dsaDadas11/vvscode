/*
 * @Author: dsaDadas11
 * @Date: 2024-07-25 20:39:12
 * @LastEditTime: 2024-07-25 20:39:22
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr long double pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
void solve()
{
	int n,r;
	cin>>n>>r;
	long double xita=pi/(n);
	long double t=sin(xita);
	cout<<fixed<<setprecision(12)<<t*r/(1-t)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}