/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:58:54
 * @LastEditTime: 2024-01-17 14:59:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
void solve()
{
	int n; cin>>n;
	string s,f; cin>>s>>f;
	int h=0,nh=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1'&&f[i]=='0') h++;
		if(s[i]=='0'&&f[i]=='1') nh++;
	}
	cout<<max(h,nh)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}