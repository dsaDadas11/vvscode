/*
 * @Author: dsaDadas11
 * @Date: 2024-07-20 15:12:36
 * @LastEditTime: 2024-07-20 15:12:40
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
	for(int i=1;i<=n;i++) cin>>a[i];
	map<int,bool> mp;
	for(int i=1;i<=n;i++)
	{
		mp[a[i]]=1;
	}
	for(int i=1;i<=1024;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(mp[a[j]^i]) cnt++;
		}
		if(cnt==n)
		{
			cout<<i<<endl;
			return;
		}
	}
	cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}