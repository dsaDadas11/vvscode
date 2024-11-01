/*
 * @Author: dsaDadas11
 * @Date: 2024-02-02 18:58:10
 * @LastEditTime: 2024-02-02 19:01:30
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
	int n;
	cin>>n;
	if(n%6==0) cout<<n/6<<endl;
	else cout<<2*(n/6)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}