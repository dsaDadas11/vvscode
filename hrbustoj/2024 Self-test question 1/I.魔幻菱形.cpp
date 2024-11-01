/*
 * @Author: dsaDadas11
 * @Date: 2024-03-11 12:34:47
 * @LastEditTime: 2024-03-11 12:34:51
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n/2+1;i++)
		{
			for(int j=1;j<=n/2+1-i;j++) cout<<" ";
			for(int j=1;j<=2*i-1;j++) cout<<"*";
			for(int j=1;j<=2*(n/2+1-i);j++) cout<<" ";
			for(int j=1;j<=2*i-1;j++) cout<<"*";
			cout<<endl;
		}
		for(int i=n/2;i>=1;i--)
		{
			for(int j=1;j<=n/2+1-i;j++) cout<<" ";
			for(int j=1;j<=2*i-1;j++) cout<<"*";
			for(int j=1;j<=2*(n/2+1-i);j++) cout<<" ";
			for(int j=1;j<=2*i-1;j++) cout<<"*";
			cout<<endl;
		}
	}
	return 0;
}