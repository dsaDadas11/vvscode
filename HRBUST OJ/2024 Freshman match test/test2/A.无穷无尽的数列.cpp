/*
 * @Author: dsaDadas11
 * @Date: 2024-11-18 22:36:57
 * @LastEditTime: 2024-11-18 22:37:07
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
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}
int niyuan(int x)
{
	return quickpow(x,mod-2);
}
int q;
int l,r;
int lx,rx;
void solve()
{
	cin>>q;
	int ni6=niyuan(6);
	int ni2=niyuan(2);
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		rx=(((r*(r+1)%mod)*(2*r+1)%mod)*ni6%mod)+(3*r*(r-1)%mod)*ni2;
		rx=(rx%mod+mod)%mod;
		l--;
		lx=(((l*(l+1)%mod)*(2*l+1)%mod)*ni6%mod)+(3*l*(l-1)%mod)*ni2;
		lx=(lx%mod+mod)%mod;
		cout<<((rx-lx)%mod+mod)%mod<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}