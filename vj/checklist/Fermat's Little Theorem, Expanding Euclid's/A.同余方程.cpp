/*
 * @Author: dsaDadas11
 * @Date: 2024-05-21 12:40:48
 * @LastEditTime: 2024-05-21 12:41:39
 * @Description: go for it!
 */
// 此题不能用费马小定理，因为费马小定理需要b为素数
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y;
void exgcd(int a,int b)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-a/b*y;
}
void solve()
{
	int a,b;
	cin>>a>>b;
	exgcd(a,b);
	cout<<(x%b+b)%b<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}