/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:52:07
 * @LastEditTime: 2024-01-17 14:52:15
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
void solve()
{
	int n; cin>>n;
	string s(n+2,0); cin>>s;
	string ss(n+2,0);
	string ans="";
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a'||s[i]=='e') ss[i]='V';
		else ss[i]='C';
	}
	for(int i=0;i<n;i++)
	{
		ans+=s[i];
		if(ss[i]=='C'&&i==n-3)
		{
			ans+=s[i+1];
			ans+=s[i+2];
			break;
		}
		else if(ss[i]=='C'&&i==n-2)
		{
			ans+=s[i+1];
			break;
		}
		else if(ss[i]=='V')
		{
			if(ss[i+2]=='C')
			{
				ans+=s[i+1];
				ans+='.';
				i++;
			}
			else ans+='.';
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