/*
 * @Author: dsaDadas11
 * @Date: 2024-07-18 10:34:52
 * @LastEditTime: 2024-07-18 10:34:57
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-2;i++)
	{
		int t1=lcm(a[i],a[i+1]);
		int t2=lcm(a[i+1],a[i+2]);
		int t3=gcd(t1,t2);
		if(t3!=a[i+1])
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}