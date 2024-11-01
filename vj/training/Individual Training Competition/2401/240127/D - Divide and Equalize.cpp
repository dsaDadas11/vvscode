/*
 * @Author: dsaDadas11
 * @Date: 2024-01-28 14:06:29
 * @LastEditTime: 2024-01-28 14:06:35
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
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		int temp=a[i];
		for(int j=2;j*j<=N;j++)
		{
			while(temp%j==0)
			{
				mp[j]++;
				temp/=j;
			}
		}
		if(temp!=1) mp[temp]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second%n!=0)
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}