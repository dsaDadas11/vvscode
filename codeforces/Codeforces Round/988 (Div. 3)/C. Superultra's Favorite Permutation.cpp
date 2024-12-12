/*
 * @Author: dsaDadas11
 * @Date: 2024-11-17 22:58:06
 * @LastEditTime: 2024-11-17 22:58:13
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
void solve()
{
	cin>>n;
	if(n<=4)
	{
		cout<<"-1"<<endl;
		return;
	}
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		if(i%2&&i!=5) ans.push_back(i);
	}
	ans.push_back(5);
	ans.push_back(4);
	for(int i=2;i<=n;i++)
	{
		if(i%2==0&&i!=4) ans.push_back(i);
	}
	for(auto i:ans) cout<<i<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}