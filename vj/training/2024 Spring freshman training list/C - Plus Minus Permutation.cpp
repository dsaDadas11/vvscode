/*
 * @Author: dsaDadas11
 * @Date: 2024-04-16 19:19:32
 * @LastEditTime: 2024-04-16 19:19:41
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
	int n,x,y;
	cin>>n>>x>>y;
	int gong=x*y/__gcd(x,y);
	int gongpos=n/gong;
	int xpos=n/x-gongpos;
	int ypos=n/y-gongpos;
	int ans=(2*n-xpos+1)*xpos/2-(1+ypos)*ypos/2;
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}