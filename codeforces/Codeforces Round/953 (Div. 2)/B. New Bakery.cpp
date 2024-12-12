/*
 * @Author: dsaDadas11
 * @Date: 2024-11-22 23:08:25
 * @LastEditTime: 2024-11-22 23:09:16
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,a,b;
void solve()
{
	cin>>n>>a>>b;
	int x=b+1-a;
	int l=min(n,b);
	if(x<=0)
	{
		cout<<n*a<<endl;
		return;
	}
	if(l<=x)
	{
		cout<<(b+1)*l-(1+l)*l/2+(n-l)*a<<endl;
		return;
	}

	cout<<(b+1)*x-(1+x)*x/2+(n-x)*a<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}