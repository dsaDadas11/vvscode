/*
 * @Author: dsaDadas11
 * @Date: 2024-03-21 18:06:33
 * @LastEditTime: 2024-03-21 18:06:49
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
	int n,k;
	cin>>n>>k;
	bool flag=0;
	int f,z;
	for(int i=1;i<=n;i++)
	{
		int ans=i*(i-1)/2+(n-i)*(n-i-1)/2;
		if(ans==k)
		{
			f=i,z=n-i;
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=f;i++) cout<<"-1"<<' ';
		for(int i=1;i<=z;i++) cout<<"1"<<' ';
		cout<<endl;
	}
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}