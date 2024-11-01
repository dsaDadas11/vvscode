/*
 * @Author: dsaDadas11
 * @Date: 2024-05-23 09:07:45
 * @LastEditTime: 2024-05-23 09:07:56
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s,ans;
void solve()
{
	unordered_map<string,int> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp[s]++;
	}
	int pos=0;
	for(auto it:mp)
	{
		if(pos<it.second)
		{
			pos=it.second;
			ans=it.first;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n&&n){solve();}
	return 0;
}