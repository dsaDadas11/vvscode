/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:49:41
 * @LastEditTime: 2024-01-17 14:49:47
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
void solve()
{
	int n; cin>>n;
	int x;
	vector<pair<int,int> > a,b,c;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a.push_back({x,i});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		b.push_back({x,i});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		c.push_back({x,i});
	}
	sort(a.begin(),a.end(),greater<pair<int,int> >());
	sort(b.begin(),b.end(),greater<pair<int,int> >());
	sort(c.begin(),c.end(),greater<pair<int,int> >());
	int ans=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				if(a[i].second!=b[j].second&&a[i].second!=c[k].second&&b[j].second!=c[k].second)
				{
					ans=max(ans,a[i].first+b[j].first+c[k].first);
				}
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