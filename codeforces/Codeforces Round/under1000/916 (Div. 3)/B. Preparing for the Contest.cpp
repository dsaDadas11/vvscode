/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:48:53
 * @LastEditTime: 2024-01-17 14:49:02
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
	int n,k; cin>>n>>k;
	for(int i=1;i<=k;i++) cout<<i<<' ';
	for(int i=n;i>k;i--) cout<<i<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}