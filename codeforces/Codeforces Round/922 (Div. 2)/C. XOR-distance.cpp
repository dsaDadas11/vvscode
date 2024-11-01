/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-31 11:58:22
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
	int a,b,r; cin>>a>>b>>r;
	int x1=0,x2=0;
	if(a<b) swap(a,b);
	for(int i=60;i>=0;i--)
	{
		int t=1ll<<i;
		if(x1+t>r) continue;
		if(abs((a^t)-(b^t))<abs(a-b))
			x1+=t;
	}
	for(int i=60;i>=0;i--)
	{
		int t=1ll<<i;
		if(x2+t>r) continue;
		if((a^t)<(b^t)) continue;
		if(abs((a^t)-(b^t))<abs(a-b))
			x2+=t;
	}
	cout<<min(abs((a^x1)-(b^x1)),abs((a^x2)-(b^x2)))<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}