/*
 * @Author: dsaDadas11
 * @Date: 2024-01-29 11:08:01
 * @LastEditTime: 2024-01-29 11:08:13
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans*=x;
		x*=x;
		y>>=1;
	}
	return ans;
}
void solve()
{
	int n,m; cin>>n>>m;
	int t=n*m;
	int wu1=0,er1=0;
	int wu2=0,er2=0;
	while(n%2==0)
	{
		n/=2;
		er1++;
	}
	while(n%5==0)
	{
		n/=5;
		wu1++;
	}
	if(er1<wu1)
	{
		while(m>=2)
		{
			m/=2;
			er2++;
			if(er1+er2==wu1) break;
		}
	}
	else if(er1>wu1)
	{
		while(m>=5)
		{
			m/=5;
			wu2++;
			if(wu1+wu2==er1) break;
		}
	}
	int cnt=0;
	while(m>=10)
	{
		m/=10;
		cnt++;
	}
	if(er2||wu2||cnt) cout<<n*m*quickpow(2,er1+er2)*quickpow(5,wu1+wu2)*quickpow(10,cnt)<<endl;
	else cout<<t<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}