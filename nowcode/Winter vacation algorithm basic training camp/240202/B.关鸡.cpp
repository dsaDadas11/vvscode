/*
 * @Author: dsaDadas11
 * @Date: 2024-02-03 11:39:38
 * @LastEditTime: 2024-02-03 11:39:45
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
	if(n==0)
	{
		cout<<"3"<<endl;
		return;
	}
	vector<pair<int,int> > v(n+7);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i].second>>v[i].first;
	}
	sort(v.begin()+1,v.begin()+1+n);
	int fl=0,fr=0;
	int mid=0;
	int fll=0,frr=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i].first>0) fr=max(fr,1ll);
		if(v[i].first<0) fl=max(fl,1ll);
		
		if(v[i].first>0&&abs(v[i].first-v[i+1].first)<=1&&v[i].second+v[i+1].second==3) fr=2;
		if(v[i].first<0&&abs(v[i].first-v[i+1].first)<=1&&v[i].second+v[i+1].second==3) fl=2;
		
		if(v[i].first==0) mid=1;
		if(v[i].first==1&&v[i].second==1) frr=1;
		if(v[i].first==-1&&v[i].second==1) fll=1;
	}
	int ans=4-fl-fr;
	int res=3-mid-frr-fll;
	if(mid||frr||fll)
	{
		if(!fll) res-=(fl==2);
		if(!frr) res-=(fr==2);
	}
	ans=min(ans,res);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}