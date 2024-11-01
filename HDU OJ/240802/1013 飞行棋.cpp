/*
 * @Author: dsaDadas11
 * @Date: 2024-08-02 14:13:38
 * @LastEditTime: 2024-08-02 14:13:51
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
const int mod=1e9+7;
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
int niyuan(int x)
{
	return quickpow(x,mod-2);
}
void solve()
{
	int n;
	cin>>n;
	cout<<(niyuan(n)+n-1)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}