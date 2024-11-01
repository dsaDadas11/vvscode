/*
 * @Author: dsaDadas11
 * @Date: 2024-04-17 16:55:28
 * @LastEditTime: 2024-04-17 16:55:34
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
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		cout<<'0'<<endl;
		for(int i=1;i<=n;i++) cout<<'0'<<endl;
		return;
	}
	if(n>=m-1) cout<<m<<endl;
	else cout<<n+1<<endl;
	for(int i=1;i<=m;i++) a[i]=i-1;
	for(int i=1;i<=n;i++)
	{
		int k=i%(m-1);
		if(k==0) k=m;
		else k++;
		for(int j=k;j<=m;j++) cout<<a[j]<<' ';
		for(int j=1;j<k;j++) cout<<a[j]<<' ';
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}