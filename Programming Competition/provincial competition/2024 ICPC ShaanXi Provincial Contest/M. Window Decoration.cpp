/*
 * @Author: dsaDadas11
 * @Date: 2024-09-02 18:42:35
 * @LastEditTime: 2024-09-02 18:42:40
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
int x,y;
set<pair<int,int> > se;
map<pair<int,int>,bool> mp;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		se.insert({x,y});
	}
	long double ans=2.0*se.size();
	for(auto [xx,yy]:se)
	{
		if(se.count({xx-1,yy})&&!mp[{xx-1,yy}])
		{
			ans-=0.5;
		}
		if(se.count({xx+1,yy})&&!mp[{xx+1,yy}])
		{
			ans-=0.5;
		}
		if(se.count({xx,yy-1})&&!mp[{xx,yy-1}])
		{
			ans-=0.5;
		}
		if(se.count({xx,yy+1})&&!mp[{xx,yy+1}])
		{
			ans-=0.5;
		}
		mp[{xx,yy}]=1;
	}
	cout<<fixed<<setprecision(8)<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}