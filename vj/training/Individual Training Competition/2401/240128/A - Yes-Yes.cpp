/*
 * @Author: dsaDadas11
 * @Date: 2024-01-28 21:58:05
 * @LastEditTime: 2024-01-28 21:58:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
char Yes[3]={'Y','e','s'};
void solve()
{
	string s;
	cin>>s;
	int len=s.size();
	bool flag=1;
	if(s[0]!='Y'&&s[0]!='e'&&s[0]!='s') flag=0;
	if(s[0]=='Y')
	{
		
		int p=0;
		for(int i=0;i<len;i++)
		{
			if(p==3) p=0;
			if(s[i]!=Yes[p]) flag=0;
			p++;
		}
	}
	else if(s[0]=='e')
	{
		int p=1;
		for(int i=0;i<len;i++)
		{
			if(p==3) p=0;
			if(s[i]!=Yes[p]) flag=0;
			p++;
		}
	}
	else if(s[0]=='s')
	{
		int p=2;
		for(int i=0;i<len;i++)
		{
			if(p==3) p=0;
			if(s[i]!=Yes[p]) flag=0;
			p++;
		}
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}