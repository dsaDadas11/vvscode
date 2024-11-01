/*
 * @Author: dsaDadas11
 * @Date: 2024-01-28 21:59:14
 * @LastEditTime: 2024-01-28 21:59:24
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
	bool a[57]={0};
	int n,s; cin>>n>>s;
	int m=0;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		a[x]=1;
		m=max(m,x);
	}
	int sum=0;
	for(int i=1;i<=m;i++)
		if(a[i]==0) sum+=i;
	if(sum==s) cout<<"YES"<<endl;
	else if(sum>s) cout<<"NO"<<endl;
	else
	{
		while(sum<s)
		{
			sum+=++m;
		}
		if(sum==s) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}