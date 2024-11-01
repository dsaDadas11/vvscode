/*
 * @Author: dsaDadas11
 * @Date: 2024-01-24 20:52:07
 * @LastEditTime: 2024-01-24 20:52:14
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
	int n; cin>>n;
	string s1[n+7]={""};
	string s2[n+7]={""};
	string s3[n+7]={""};
	unordered_map<string,int> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i];
		mp[s1[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s2[i];
		mp[s2[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s3[i];
		mp[s3[i]]++;
	}
	int ans1=0,ans2=0,ans3=0;
	for(int i=1;i<=n;i++)
	{
		if(mp[s1[i]]==1) ans1+=3;
		if(mp[s1[i]]==2) ans1+=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[s2[i]]==1) ans2+=3;
		if(mp[s2[i]]==2) ans2+=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[s3[i]]==1) ans3+=3;
		if(mp[s3[i]]==2) ans3+=1;
	}
	cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}