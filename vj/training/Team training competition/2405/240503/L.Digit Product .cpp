/*
 * @Author: dsaDadas11
 * @Date: 2024-05-07 19:16:39
 * @LastEditTime: 2024-05-07 19:16:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
void solve()
{
	int l,r;
	cin>>l>>r;
	int sum=1,len;
	string s;
	if(r-l+1>=10)
	{
		cout<<'0'<<endl;
		return;
	}
	for(int i=l;i<=r;i++)
	{
		s=to_string(i);
		len=s.size();
		int t=1;
		for(int j=0;j<len;j++)
		{
			t*=(s[j]-'0');
			t%=mod;
			if(t==0)
			{
				cout<<'0'<<endl;
				return;
			}
		}
		sum=(sum*t)%mod;
	}
	cout<<sum<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}