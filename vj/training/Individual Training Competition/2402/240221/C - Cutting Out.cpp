/*
 * @Author: dsaDadas11
 * @Date: 2024-02-22 11:13:45
 * @LastEditTime: 2024-02-22 11:13:56
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
int n,k;
map<int,int> mp;
bool check(int mid)
{
	int cnt=0;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(mid<=it->second) cnt+=it->second/mid;
	}
	if(cnt>=k) return 1;
	else return 0;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	int l=1,r=n,mid=0,num=1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			num=mid;
		}
		else r=mid;
	}
	vector<int> ans;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		for(int i=1;i<=it->second/num;i++)
		{
			ans.push_back(it->first);
			if((int)ans.size()==k) break;
		}
		if((int)ans.size()==k) break;
	}
	for(auto it : ans) cout<<it<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}