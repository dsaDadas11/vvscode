/*
 * @Author: dsaDadas11
 * @Date: 2024-07-28 15:48:13
 * @LastEditTime: 2024-07-28 15:48:23
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
pair<int,int> p[N];
bool vis[N];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.first>y.first;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first;
		p[i].second=i;
	}
	sort(p+1,p+1+n,cmp);
	int ans=0;
	for(int i=1;i<=m*k;i++)
	{
		vis[p[i].second]=1;
		ans+=p[i].first;
	}
	cout<<ans<<endl;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) cnt++;
		if(k==1) break;
		if(cnt==m)
		{
			cout<<i<<' ';
			cnt=0;
			k--;
		}
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