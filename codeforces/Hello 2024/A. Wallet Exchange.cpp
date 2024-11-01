/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 15:01:26
 * @LastEditTime: 2024-01-17 15:01:31
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
	int a,b; cin>>a>>b;
	if(abs(a-b)%2==1) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}