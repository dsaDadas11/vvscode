/*
 * @Author: dsaDadas11
 * @Date: 2024-11-09 12:50:57
 * @LastEditTime: 2024-11-09 13:14:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
void solve()
{
	cin>>s;
	int pos=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='-')
		{
			pos=i;
			break;
		}
	}
	string t1=s.substr(0,pos);
	string t2=s.substr(pos+1);
	int n1=stoi(t1);
	int n2=stoi(t2);
	cout<<n1-n2<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}