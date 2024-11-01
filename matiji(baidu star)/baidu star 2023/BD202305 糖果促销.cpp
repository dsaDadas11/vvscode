/*
 * @Author: dsaDadas11
 * @Date: 2024-05-27 17:21:34
 * @LastEditTime: 2024-05-27 17:24:46
 * @Description: go for it!
 */
/*
解题思路：
这道题用的是二分(数论菜鸟)
二分写的没问题，但是没有特判数据，所以TLE了5个测试点
1.p==1
  (1) k!=0 只需要买一个糖果
  (2) k==0 不需买糖果
2.k==0时不需要买糖果
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int p,k;
bool check(int p,int k,int mid)
{
	int ans=mid;
	int sum=mid;
	int d1,d2;
	while(sum>=p)
	{
		d1=sum/p;
		d2=sum%p;
		sum=d1+d2;
		ans+=d1;
		if(ans>=k) return 1;
	}
	if(ans>=k) return 1;
	return 0;
}
void solve()
{
	cin>>p>>k;
	if(k==0)
	{
		cout<<'0'<<endl;
		return;
	}
	if(p==1)
	{
		cout<<'1'<<endl;
		return;
	}
	int l=1,r=k;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(p,k,mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}