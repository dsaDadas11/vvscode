/*
 * @Author: dsaDadas11
 * @Date: 2024-11-10 12:38:29
 * @LastEditTime: 2024-11-10 12:38:40
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
	string s,t;
	cin>>s>>t;
	swap(s[0],t[0]);
	cout<<s<<' '<<t<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}