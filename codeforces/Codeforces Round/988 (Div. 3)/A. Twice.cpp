/*
 * @Author: dsaDadas11
 * @Date: 2024-11-17 22:37:27
 * @LastEditTime: 2024-11-17 22:39:01
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
int a[107];
void solve()
{
	map<int,int> mp;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	int ans=0;
	for(auto [x,y]:mp)
	{
		if(y>=2) ans+=(y)/2;
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