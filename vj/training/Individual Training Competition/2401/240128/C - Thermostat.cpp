/*
 * @Author: dsaDadas11
 * @Date: 2024-01-28 22:00:27
 * @LastEditTime: 2024-01-28 22:01:13
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
	int l,r,x; cin>>l>>r>>x;
	int a,b; cin>>a>>b;
	if(a==b) cout<<"0"<<endl;
	else if(a<b)
	{
		if(a+x<=b) cout<<"1"<<endl;
		else if(b+x<=r||a-x>=l) cout<<"2"<<endl;
		else if(b-x>=l&&r-a>=x) cout<<"3"<<endl;
		else cout<<"-1"<<endl;
	}
	else
	{
		if(b+x<=a) cout<<"1"<<endl;
		else if(a+x<=r||b-x>=l) cout<<"2"<<endl;
		else if(a-x>=l&&r-b>=x) cout<<"3"<<endl;
		else cout<<"-1"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}