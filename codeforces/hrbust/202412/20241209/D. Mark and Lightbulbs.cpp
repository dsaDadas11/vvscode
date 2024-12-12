/*
 * @Author: dsaDadas11
 * @Date: 2024-12-09 20:00:31
 * @LastEditTime: 2024-12-09 20:00:47
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
string s,t;
void solve()
{
	cin>>n;
	cin>>s>>t;
	s=' '+s,t=' '+t;
	if(s[1]!=t[1]||s[n]!=t[n])
	{
		cout<<"-1"<<endl;
		return;
	}
	vector<int> v1,v2;
	for(int i=2;i<=n;i++)
	{
		if(s[i]==s[i-1]) continue;
		v1.push_back(i);
	}
	for(int i=2;i<=n;i++)
	{
		if(t[i]==t[i-1]) continue;
		v2.push_back(i);
	}
	int len=v1.size();
	if(len!=(int)v2.size())
	{
		cout<<"-1"<<endl;
		return;
	}
	int ans=0;
	for(int i=0;i<(int)v1.size();i++)
	{
		ans+=abs(v1[i]-v2[i]);
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