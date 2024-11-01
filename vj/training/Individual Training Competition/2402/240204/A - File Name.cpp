/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-02-04 19:51:36
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
	int n; cin>>n;
	string s; cin>>s;
	int cnt=0,cs=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='x') cs++;
		if(cs>=3)
		{
			cnt++;
		}
		if(s[i+1]!=s[i]) cs=0;
	}
	cout<<cnt<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}