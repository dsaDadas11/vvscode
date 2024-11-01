/*
 * @Author: dsaDadas11
 * @Date: 2024-02-04 21:16:42
 * @LastEditTime: 2024-02-04 21:16:53
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
	map<int,int> dp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[a[i]]=dp[a[i]-1]+1;
	}
	int mm=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		if(mm<dp[a[i]])
		{
			mm=dp[a[i]];
			pos=i;
		}
	}
	vector<int> ans;
	int st=a[pos]-mm+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==st)
		{
			ans.push_back(i);
			st++;
		}
		if(st==a[pos]+1) break;
	}
	cout<<mm<<endl;
	for(auto it:ans) cout<<it<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}