/*
 * @Author: dsaDadas11
 * @Date: 2024-09-01 20:37:58
 * @LastEditTime: 2024-09-01 20:38:18
 * @Description: go for it!
 */
/*
 二进制写的有点迷...
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
string ans="xwr";
void solve()
{
	cin>>s;
	vector<int> bin[7];
	for(int i=0;i<3;i++)
	{
		int a=s[i]-'0';
		while(a)
		{
			bin[i].push_back(a%2);
			a/=2;
		}
		while(bin[i].size()<3) bin[i].push_back(0);
		for(int j=2;j>=0;j--)
		{
			if(bin[i][j]) cout<<ans[j];
			else cout<<'-';
		}
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}