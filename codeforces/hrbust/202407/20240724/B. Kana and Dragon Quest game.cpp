/*
 * @Author: dsaDadas11
 * @Date: 2024-07-24 14:50:58
 * @LastEditTime: 2024-07-24 14:51:12
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
	int x,n,m;
	cin>>x>>n>>m;
	for(int i=1;i<=n;i++)
	{
		if(x/2+10>x) break;
		x=x/2+10;
		if(x<=0)
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	if(x<=m*10) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}