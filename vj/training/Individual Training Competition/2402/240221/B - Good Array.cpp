/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-02-21 20:39:17
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
	int sum=0;
	int m1=0,m2=0;
	unordered_map<int,int> mp;
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		mp[a[i]]++;
		m1=max(a[i],m1);
	}
	if(mp[m1]>1) m2=m1;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=m1) m2=max(a[i],m2);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==m1)
		{
			if(sum-a[i]-m2==m2) ans.push_back(i);
		}
		else
		{
			if(sum-a[i]-m1==m1) ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}