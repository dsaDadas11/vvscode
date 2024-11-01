/*
 * @Author: dsaDadas11
 * @Date: 2024-02-03 21:42:41
 * @LastEditTime: 2024-02-03 21:42:55
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n; cin>>n;
	string s; cin>>s;
	map<string,int> mp;
	vector<pair<int,string> > v;
	for(int i=0;i<n-1;i++)
	{
		//if(s[i]==s[i+1]) continue;
		string t="";
		t.push_back(s[i]);
		t.push_back(s[i+1]);
		mp[t]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		v.push_back({it->second,it->first});
	}
	sort(v.begin(),v.end(),greater<>());
	cout<<v[0].second<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}