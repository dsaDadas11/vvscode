/*
 * @Author: dsaDadas11
 * @Date: 2024-02-07 00:31:00
 * @LastEditTime: 2024-02-07 00:31:09
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	string ans;
	map<int,int> z;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(z[j]==a[i])
			{
				ans.push_back('a'+j);
				z[j]++;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}