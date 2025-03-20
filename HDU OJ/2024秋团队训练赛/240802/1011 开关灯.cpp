/*
 * @Author: dsaDadas11
 * @Date: 2024-08-02 14:13:11
 * @LastEditTime: 2024-08-02 14:13:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
int n;
void solve()
{
	cin>>n;
	if(n==1||n==2)
	{
		cout<<"2"<<endl;
		return;
	}
	else if(n%3==0)
	{
		cout<<quickpow(2,n)<<endl;
		return;
	}
	else if(n%3==1)
	{
		cout<<quickpow(2,n)<<endl;
		return;
	}
	else if(n%3==2)
	{
		cout<<quickpow(2,n-1)<<endl;
		return;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}