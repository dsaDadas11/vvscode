/*
 * @Author: dsaDadas11
 * @Date: 2024-01-31 19:55:31
 * @LastEditTime: 2024-01-31 19:55:36
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
	string s=""; cin>>s;
	string ans="";
	char c;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='0')
		{
			int t=(s[i-2]-'0')*10+(s[i-1]-'0');
			c=(t+'a'-1);
			i-=2;
			ans=c+ans;
		}
		else
		{
			int t=(s[i]-'0');
			c=(t+'a'-1);
			ans=c+ans;
		}
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