/*
 * @Author: dsaDadas11
 * @Date: 2024-02-03 21:44:23
 * @LastEditTime: 2024-02-03 21:44:51
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[107];
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.first==p2.first) return p1.second>p2.second;
	else return p1.first<p2.first;
}
void solve()
{
	int n; cin>>n;
	vector<pair<int,int> >v; //2 3
	map<pair<int,int>,int> mp; //p
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int t=a[i];
		int er=0,san=0;
		while(t%2==0)
		{
			t/=2;
			er++;
		}
		while(t%3==0)
		{
			t/=3;
			san++;
		}
		v.push_back({er,san});
		mp[{er,san}]=i;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++)
	{
		cout<<a[mp[{v[i].first,v[i].second}]]<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}