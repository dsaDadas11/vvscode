/*
 * @Author: dsaDadas11
 * @Date: 2024-11-23 09:33:34
 * @LastEditTime: 2024-11-23 09:33:44
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
	cin>>n;
	int x;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		ans|=x;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}