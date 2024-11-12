/*
 * @Author: dsaDadas11
 * @Date: 2024-11-09 12:20:10
 * @LastEditTime: 2024-11-09 12:20:13
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
	int t=0;
	for(int i=1;;i++)
	{
		t=i*i*i;
		if(t>=2024) break;
	}
	cout<<t-2024<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}