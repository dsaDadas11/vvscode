/*
 * @Author: dsaDadas11
 * @Date: 2024-03-21 21:14:50
 * @LastEditTime: 2024-03-21 21:14:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct op
{
	int a,b;
	int d;
	bool operator<(const op& that) const
	{
		return d<that.d;
	}
}c[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i].a>>c[i].b;
		c[i].d=c[i].b-c[i].a;		
	}
	sort(c+1,c+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=c[i].a*(i-1)+c[i].b*(n-i);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}