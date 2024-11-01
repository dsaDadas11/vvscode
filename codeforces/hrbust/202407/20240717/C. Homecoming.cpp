/*
 * @Author: dsaDadas11
 * @Date: 2024-07-17 15:38:59
 * @LastEditTime: 2024-07-17 15:39:06
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
	int a,b,p;
	string s;
	cin>>a>>b>>p>>s;
	int len=s.size();
	char c;
	bool flag=0;
	for(int i=len-2;i>=0;i--)
	{
		if(c!=s[i])
		{
			c=s[i];
			if(c=='A') p-=a;
			else p-=b;
			if(p<0)
			{
				cout<<i+2<<endl;
				flag=1;
				break;
			}
		}
	}
	if(!flag) cout<<'1'<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}