/*
 * @Author: dsaDadas11
 * @Date: 2024-09-26 21:27:49
 * @LastEditTime: 2024-09-26 21:27:59
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int p1,p2,p3;
void solve()
{
	cin>>p1>>p2>>p3;
	int sum=p1+p2+p3;
	if(sum%2) // 不管是平局还是一方赢，总分都是加两分
	{
		cout<<"-1"<<endl;
		return;
	}
	if(p1+p2<=p3) //p1,p2能和p3平局，然后p3赢p1,p2
	{
		cout<<p1+p2<<endl;
	}
	else // p1,p2平局-2，然后将分数降到p1+p2==p3回到第一种情况
	{
		cout<<(p3-(p1+p2))/2+p1+p2<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}