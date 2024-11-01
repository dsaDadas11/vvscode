/*
 * @Author: dsaDadas11
 * @Date: 2024-05-23 09:08:04
 * @LastEditTime: 2024-05-23 09:08:14
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
string s[4][M];
void solve()
{
	unordered_map<string,int> mp;
	cin>>n;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>s[i][j];
			mp[s[i][j]]++;
		}
	}
	int ans[4]={0};
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[s[i][j]]==1) ans[i]+=3;
			else if(mp[s[i][j]]==2) ans[i]+=1;
		}
	}
	for(int i=1;i<=3;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}