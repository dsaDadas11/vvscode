/*
 * @Author: dsaDadas11
 * @Date: 2024-08-05 21:02:24
 * @LastEditTime: 2024-08-05 21:02:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m;
int b[N],e[N],s[N],t[N];
int last[N];
void solve()
{
	cin>>n>>m;
	vector<pair<int,pair<int,int> > > pand;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>e[i];
		pand.push_back({b[i],{e[i],0}});
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s[i]>>t[i];
		pand.push_back({s[i],{t[i],1}});
		last[i]=2*(t[i]-s[i]);
	}
	// 排完序之后暴力判断
	sort(pand.begin(),pand.end());
	for(int i=1;i<(int)pand.size()-1;i++)
	{
		int x=pand[i].first;
		int y=pand[i].second.first;
		int z=pand[i].second.second;
		if(z==0)
		{
			int xx=pand[i-1].first;
			int yy=pand[i-1].second.first;
			int zz=pand[i-1].second.second;
			if(zz==1)
			{
				if(yy>x)
				{
					cout<<"No"<<endl;
					return;
				}
			}
			xx=pand[i+1].first;
			yy=pand[i+1].second.first;
			zz=pand[i+1].second.second;
			if(zz==1)
			{
				if(xx<y)
				{
					cout<<"No"<<endl;
					return;
				}
			}
		}
	}
	// 睡 上课
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(b[i]-t[j+1]>=0&&j+1<=m) j++;
		if(t[j]+last[j]<e[i]||j>m)
		{
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("1004.in", "r", stdin);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}