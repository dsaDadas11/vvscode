/*
 * @Author: dsaDadas11
 * @Date: 2024-05-23 09:08:33
 * @LastEditTime: 2024-05-23 09:10:03
 * @Description: go for it!
 */
// 解法一：用pow处理三次根号
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,d,j;
void solve()
{
	cin>>x;
	for(int i=1;i*i*i<x;i++)
	{
		d=x-i*i*i;
		j=pow(d,1.0/3);
		for(int k=j-50;k<=j+50;k++)
		{
			if(i*i*i+k*k*k==x)
			{
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

// 解法二：二分三次根号答案(注意范围，不然会爆long long)
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x;
void solve()
{
	cin>>x;
	for(int i=1;i*i*i<x;i++)
	{
		int l=1,r=10000;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(i*i*i+mid*mid*mid<x) l=mid+1;
			else r=mid;
		}
		if(i*i*i+l*l*l==x)
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}