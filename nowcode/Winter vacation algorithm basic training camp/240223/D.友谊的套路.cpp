/*
 * @Author: dsaDadas11
 * @Date: 2024-02-23 16:19:13
 * @LastEditTime: 2024-02-23 16:19:19
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
	double p; cin>>p;
    cout<<1.0*(1.0*p*p*(1-p)*(1-p)*(1-p)+1.0*(1-p)*(1-p)*p*p*p)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}