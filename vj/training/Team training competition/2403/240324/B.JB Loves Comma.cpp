/*
 * @Author: dsaDadas11
 * @Date: 2024-03-26 21:19:57
 * @LastEditTime: 2024-03-26 21:20:02
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
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		cout<<s[i];
		if(i>=2&&(s[i-2]=='c'&&s[i-1]=='j'&&s[i]=='b'))
		{
			cout<<',';
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}