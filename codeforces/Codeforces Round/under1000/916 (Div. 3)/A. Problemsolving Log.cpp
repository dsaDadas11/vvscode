/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:48:24
 * @LastEditTime: 2024-01-17 14:48:31
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
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		char c; cin>>c;
		mp[(int)(c-'A'+1)]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(mp[i]>=i) cnt++;
	}
	cout<<cnt<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}