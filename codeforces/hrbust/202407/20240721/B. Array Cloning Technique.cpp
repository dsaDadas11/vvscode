/*
 * @Author: dsaDadas11
 * @Date: 2024-07-21 14:20:42
 * @LastEditTime: 2024-07-21 14:20:47
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	int maxn=0;
	for(auto it:mp)
	{
		maxn=max(maxn,it.second);
	}
	if(maxn==n)
	{
		cout<<"0"<<endl;
		return;
	}
	int ans=0;
	while(1)
	{
		if(maxn*2>n) break;
		ans++;
		ans+=maxn;
		maxn*=2;
	}
	if(maxn!=n)
	{
		ans++;
		ans+=n-maxn;
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