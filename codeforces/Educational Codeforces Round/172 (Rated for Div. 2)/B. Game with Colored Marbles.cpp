/*
 * @Author: dsaDadas11
 * @Date: 2024-12-02 22:57:47
 * @LastEditTime: 2024-12-02 22:58:05
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
int c[N];
void solve()
{
	cin>>n;
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		mp[c[i]]++;
	}
	int ans=0;
	vector<pair<int,int> > p;
	for(auto [x,y]:mp)
	{
		p.push_back({y,x}); // 数量 弹珠
	}
	sort(p.begin(),p.end());
	int stp=1;
	for(int i=0;i<(int)p.size();i++)
	{
		if(stp&1)
		{
			if(p[i].first==1) ans+=2,stp++;
			else
			{
				stp+=p[i].first;
				ans++;
			}
		}
		else
		{
			if(p[i].first==1)
			{
				stp++;
			}
			else
			{
				stp+=p[i].first;
				ans++;
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