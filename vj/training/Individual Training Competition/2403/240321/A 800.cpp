/*
 * @Author: dsaDadas11
 * @Date: 2024-03-21 21:13:31
 * @LastEditTime: 2024-03-21 21:13:41
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
	int n,m;
	cin>>n>>m;
	if(n==1||m==1) cout<<"YES"<<endl;
	else if(n==2&&m==2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}