/*
 * @Author: dsaDadas11
 * @Date: 2024-07-19 15:19:10
 * @LastEditTime: 2024-07-19 15:19:14
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
	int n,k;
	cin>>n>>k;
	int cnt1=0;
	while(n)
	{
		if(n%2) cnt1++;
		n>>=1;
	}
	int ans=1;
	for(int i=1;i<=cnt1;i++) ans*=12;
	for(int i=1;i<=k-cnt1;i++) ans*=4;
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}