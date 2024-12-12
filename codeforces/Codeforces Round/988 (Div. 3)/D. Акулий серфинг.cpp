/*
 * @Author: dsaDadas11
 * @Date: 2024-11-17 23:46:08
 * @LastEditTime: 2024-11-18 09:35:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,L;
pair<int,int> p1[N];
pair<int,int> p2[N];
priority_queue<int> pq;
void solve()
{
	cin>>n>>m>>L;
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n;i++)
	{
		cin>>p1[i].first>>p1[i].second;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>p2[i].first>>p2[i].second;
	}
	int rx=1;
	int sum=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(p2[rx].first<p1[i].first&&rx<=m)
		{
			pq.push(p2[rx].second);
			rx++;
		}
		while(!pq.empty()&&sum<=p1[i].second-p1[i].first+1)
		{
			sum+=pq.top();
			ans++;
			pq.pop();
		}
		if(sum<=p1[i].second-p1[i].first+1)
		{
			cout<<"-1"<<endl;
			return;
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