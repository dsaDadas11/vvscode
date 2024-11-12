/*
 * @Author: dsaDadas11
 * @Date: 2024-10-05 21:31:26
 * @LastEditTime: 2024-10-05 21:31:32
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int p[70];
void pre()
{
	p[0]=1;
	for(int i=1;i<=65;i++)
	{
		p[i]=2*p[i-1];
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n+1;i++)
	{
		if((k-p[i-1])%p[i]==0)
		{
			cout<<i<<endl;
			return;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}