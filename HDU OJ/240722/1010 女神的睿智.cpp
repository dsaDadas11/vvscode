/*
 * @Author: dsaDadas11
 * @Date: 2024-07-22 15:37:48
 * @LastEditTime: 2024-07-22 16:47:38
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
string s;
void solve()
{
	cin>>s;
	string jiejin="";
	unordered_map<char,int> mp;
	for(int i=0;i<8;i++)
	{
		mp[s[i]]++;
	}
	for(int i=0;i<8;i+=2)
	{
		jiejin.push_back(s[i]);
	}
	string dajiejin="";
	for(int i=0;i<4;i+=2)
	{
		dajiejin.push_back(jiejin[i]);
	}
	if(dajiejin[0]!=dajiejin[1])
	{
		if(mp[dajiejin[0]]>mp[dajiejin[1]])
		{
			cout<<dajiejin[0]<<endl;
		}
		else if(mp[dajiejin[0]]==mp[dajiejin[1]])
		{
			cout<<"N"<<endl;
		}
		else cout<<dajiejin[1]<<endl;
	}
	else cout<<dajiejin[1]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}