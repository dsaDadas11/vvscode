/*
 * @Author: dsaDadas11
 * @Date: 2024-02-07 00:30:37
 * @LastEditTime: 2024-02-07 00:30:48
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
	int l=-1,r=-1;
	for(int i=0;i<n;i++)
	{
		if(l==-1&&s[i]=='B') l=i;
		if(s[i]=='B') r=i;
	}
	if(l==-1) cout<<'0'<<endl;
	else cout<<r-l+1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}