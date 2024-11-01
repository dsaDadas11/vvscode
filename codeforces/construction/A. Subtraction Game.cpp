/*
 * @Author: dsaDadas11
 * @Date: 2024-08-28 21:16:04
 * @LastEditTime: 2024-08-28 21:16:20
 * @Description: go for it!
 */
// URL:https://codeforces.com/problemset/problem/1844/A
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b;
void solve()
{
	cin>>a>>b;
	if(a>1)
	{
		cout<<"1"<<endl;
		return;
	}
	else
	{
		cout<<a+b<<endl;
		return;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}