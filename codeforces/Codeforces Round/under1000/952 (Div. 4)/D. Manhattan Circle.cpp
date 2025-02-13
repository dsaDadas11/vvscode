/*
 * @Author: dsaDadas11
 * @Date: 2024-11-10 13:04:58
 * @LastEditTime: 2024-11-10 13:05:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	return p1.second<p2.second;
}
void solve()
{
	cin>>n>>m;
	vector<vector<char> > c(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
	}
	vector<pair<int,int> > p;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]=='#') p.push_back({i,j});
		}
	}
	sort(p.begin(),p.end());
	int ansx=(p[0].first+p.back().first)/2;
	sort(p.begin(),p.end(),cmp);
	int ansy=(p[0].second+p.back().second)/2;
	cout<<ansx<<' '<<ansy<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}