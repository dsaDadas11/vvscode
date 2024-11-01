/*
 * @Author: dsaDadas11
 * @Date: 2024-07-28 15:47:51
 * @LastEditTime: 2024-07-28 15:48:00
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
	int len=s.size();
	int cnt0=0,cnt1=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='1') cnt1++;
		else cnt0++;
		if(s[i]=='0')
		{
			if(cnt0%2==1)
			{
				cout<<"1 1"<<endl;
			}
			else
			{
				cout<<"3 1"<<endl;
			}
		}
		else
		{
			if(cnt1%2==1)
			{
				cout<<"4 3"<<endl;
			}
			else
			{
				cout<<"4 1"<<endl;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}