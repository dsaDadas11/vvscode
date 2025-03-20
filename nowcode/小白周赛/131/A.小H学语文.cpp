/*
 * @Author: dsaDadas11
 * @Date: 2024-11-01 20:50:23
 * @LastEditTime: 2024-11-01 20:50:34
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
pair<int,int> h[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i].first;
		h[i].second=i;
	}
	sort(h+1,h+1+n);
	int st=0;
	int mx=0;
	int las=0;
	for(int i=n;i>=1;i--)
	{
		st++;
		if(st*st*h[i].first>=mx)
		{
			mx=st*st*h[i].first;
			las=st;
		}
	}
	vector<int> ans;
	for(int i=n;i>=n-las+1;i--) ans.push_back(h[i].second);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto i:ans) cout<<i<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}