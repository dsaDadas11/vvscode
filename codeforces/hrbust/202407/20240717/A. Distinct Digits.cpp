/*
 * @Author: dsaDadas11
 * @Date: 2024-07-17 15:14:15
 * @LastEditTime: 2024-07-17 15:14:21
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
	int l,r;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		set<int> se;
		string s=to_string(i);
		for(int j=0;j<(int)s.size();j++)
		{
			se.insert(s[j]-'0');
		}
		if(se.size()==s.size())
		{
			cout<<i<<endl;
			return;
		}
	}
	cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}