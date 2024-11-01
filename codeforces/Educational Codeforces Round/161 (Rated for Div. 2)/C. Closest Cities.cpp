/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-19 13:51:52
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int a[N],pre1[N],dis1[N],pre2[N],dis2[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(i==1) dis1[i]=1;
		else
		{
			if(abs(a[i+1]-a[i])>abs(a[i]-a[i-1])) dis1[i]=abs(a[i+1]-a[i]);
			else dis1[i]=1;
		}
	}
	for(int i=1;i<n;i++)
	{
		pre1[i]=pre1[i-1]+dis1[i];
	}
	for(int i=n;i>1;i--)
	{
		if(i==n) dis2[i]=1;
		else
		{
			if(abs(a[i-1]-a[i])>abs(a[i+1]-a[i])) dis2[i]=abs(a[i]-a[i-1]);
			else dis2[i]=1;
		}
	}
	for(int i=2;i<=n;i++)
	{
		pre2[i]=pre2[i-1]+dis2[i];
	}
	int m; cin>>m;
	while(m--)
	{
		int x,y; cin>>x>>y;
		if(y>=x) cout<<pre1[y-1]-pre1[x-1]<<endl;
		else cout<<abs(pre2[y]-pre2[x])<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}