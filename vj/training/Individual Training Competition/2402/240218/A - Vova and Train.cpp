/*
 * @Author: dsaDadas11
 * @Date: 2024-02-18 19:52:27
 * @LastEditTime: 2024-02-18 19:52:35
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
	int L,v,l,r; cin>>L>>v>>l>>r;
	cout<<(l-1)/v+L/v-r/v<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}