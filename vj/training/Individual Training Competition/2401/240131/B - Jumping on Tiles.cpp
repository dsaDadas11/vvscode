/*
 * @Author: dsaDadas11
 * @Date: 2024-02-01 11:15:29
 * @LastEditTime: 2024-02-01 11:15:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
void solve()
{
	string s; cin>>s;
	int n=s.size();
	int cost=abs(s[0]-s[n-1]);
	vector<pair<char,int> > v;
	for(int i=0;i<n;i++)
	{
		if(s[0]>s[n-1]) v.push_back({s[i],i*-1});
		else v.push_back({s[i],i});
	}
	if(s[0]<=s[n-1]) sort(v.begin(),v.end());
	else sort(v.begin(),v.end(),greater<>());
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		if(v[i].first<=max(s[0],s[n-1])&&v[i].first>=min(s[0],s[n-1]))
		{
			if(s[0]>s[n-1]) ans.push_back(v[i].second*-1);
			else ans.push_back(v[i].second);
		}
	}
	cout<<cost<<' '<<ans.size()<<endl;
	for(auto it:ans)
	{
		cout<<it+1<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}