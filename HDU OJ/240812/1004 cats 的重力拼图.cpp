/*
 * @Author: dsaDadas11
 * @Date: 2024-08-12 13:38:06
 * @LastEditTime: 2024-08-12 13:38:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,a,b;
void solve()
{
	cin>>n>>m>>a>>b;
	if(n==1)
	{
		cout<<m<<endl;
		return;
	}
	if(m==1)
	{
		cout<<n<<endl;
		return;
	}
	if((a==n||a==1)&&(b==1||b==m))
	{
		cout<<2*(n+m-2)<<endl;
		return;
	}
	if(b==1||b==m)
	{
		cout<<2*(n+m-2)+m-2<<endl;
		return;
	}
	if(a==1||a==n)
	{
		cout<<2*(n+m-2)+n-2<<endl;
		return;
	}
	if(n>m) cout<<2*(n+m-2)+n-2<<endl;
	else cout<<2*(n+m-2)+m-2<<endl;
	return;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}