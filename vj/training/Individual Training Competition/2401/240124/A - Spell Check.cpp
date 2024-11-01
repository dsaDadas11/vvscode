/*
 * @Author: dsaDadas11
 * @Date: 2024-01-24 20:51:25
 * @LastEditTime: 2024-01-24 20:51:33
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
	string s; cin>>s;
	if(n!=5) cout<<"NO"<<endl;
	else
	{
		bool f1=0,f2=0,f3=0,f4=0,f5=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='T') f1=1;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='i') f2=1;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='m') f3=1;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='u') f4=1;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='r') f5=1;
		}
		if(f1&&f2&&f3&&f4&&f5) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}