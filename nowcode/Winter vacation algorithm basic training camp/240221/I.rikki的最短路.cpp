/*
 * @Author: dsaDadas11
 * @Date: 2024-02-21 18:39:14
 * @LastEditTime: 2024-02-21 18:39:32
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
	int t,a,k; cin>>t>>a>>k;
	if(t*a>0)
	{
		if(abs(a)<=abs(t)) cout<<abs(t)<<endl;
		else cout<<2*abs(a)-abs(t)<<endl;
	}
	else if(t*a<0)
	{
		if(abs(a)<=k) cout<<2*abs(a)+abs(t)<<endl;
		else cout<<2*abs(a)+3*abs(t)<<endl;
	}
	else if(t==0&&a!=0)
	{
		cout<<2*abs(a)<<endl;
	}
	else if(a==0&&t!=0)
	{
		cout<<abs(t)<<endl;
	}
	else if(a==0&&t==0)
	{
		cout<<"0"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}