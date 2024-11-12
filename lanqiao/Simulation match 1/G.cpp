/*
 * @Author: dsaDadas11
 * @Date: 2024-11-09 12:47:14
 * @LastEditTime: 2024-11-09 13:14:15
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
string s;
void solve()
{
	cin>>s;
	int maxn=0;
	for(int i=0;i<s.size();i++)
	{
		maxn=max(maxn,(int)(s[i]-'0'));
	}
	cout<<maxn<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}