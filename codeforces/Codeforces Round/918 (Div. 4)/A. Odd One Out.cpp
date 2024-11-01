/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:51:17
 * @LastEditTime: 2024-01-17 14:51:23
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
void solve()
{
	int a,b,c; cin>>a>>b>>c;
	if(a==b) cout<<c<<endl;
	if(a==c) cout<<b<<endl;
	if(b==c) cout<<a<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}