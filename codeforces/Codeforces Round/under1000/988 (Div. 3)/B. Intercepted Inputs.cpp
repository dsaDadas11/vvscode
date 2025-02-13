/*
 * @Author: dsaDadas11
 * @Date: 2024-11-17 22:45:00
 * @LastEditTime: 2024-11-17 22:45:05
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int k;
int a[N];
void solve()
{
	cin>>k;
	for(int i=1;i<=k;i++) cin>>a[i];
	map<int,int> mp;
	for(int i=1;i<=k;i++)
	{
		mp[a[i]]++;
	}
	int sum=k-2;
	for(int i=1;i<=k;i++)
	{
		if((k-2)%a[i]==0&&mp[(k-2)/a[i]])
		{
			if((k-2)==a[i]*a[i])
			{
				if(mp[a[i]]>=2)
				{
					cout<<a[i]<<' '<<a[i]<<endl;
					return;
				}
				continue;
			}
			cout<<a[i]<<' '<<(k-2)/a[i]<<endl;
			return;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}