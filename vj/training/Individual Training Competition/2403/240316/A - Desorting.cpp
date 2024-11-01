/*
 * @Author: dsaDadas11
 * @Date: 2024-03-16 16:25:19
 * @LastEditTime: 2024-03-16 16:25:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
	bool flag=0;
	int d=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) flag=1;
		if(i>=2) d=min(a[i]-a[i-1],d);
	}
	if(flag) cout<<"0"<<endl;
	else
	{
		if(d%2==0) cout<<d/2+1<<endl;
		else cout<<(d+1)/2<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}