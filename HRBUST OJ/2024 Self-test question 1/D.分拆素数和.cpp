/*
 * @Author: dsaDadas11
 * @Date: 2024-03-11 12:24:22
 * @LastEditTime: 2024-03-11 12:24:37
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
unordered_map<int,bool> mp;
int a[N];
int p[N];
int cnt;
void pre()
{
	for(int i=2;i<N;i++)
	{
		if(!a[i])
		{
			p[++cnt]=i;
			mp[i]=1;
		}
		for(int j=1;j<=cnt&&(ll)p[j]*i<N;j++)
		{
			a[p[j]*i]=p[j];
			if(!i%p[j]) break;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	pre();
	while(cin>>n)
	{
		int ans=0;
		for(int i=2;i<n/2;i++)
		{
			if(mp[i]&&mp[n-i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}