/*
 * @Author: dsaDadas11
 * @Date: 2024-03-31 22:38:27
 * @LastEditTime: 2024-03-31 22:38:31
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
	int n,ans=0,x;
	cin>>n;
	map<int,int> mp;
	for(int i=1;i<n;i++)
	{
		cin>>x;
		mp[x]++;
	}
	for(auto it:mp)
	{
		ans+=it.second-1;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}