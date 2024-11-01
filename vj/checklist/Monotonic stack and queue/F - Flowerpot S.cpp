/*
 * @Author: dsaDadas11
 * @Date: 2024-01-27 13:02:21
 * @LastEditTime: 2024-03-08 12:49:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
pair<int,int> a[N];
deque<int> deq1,deq2;
void solve()
{
	int n,d; cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+1+n);
	int ans=1e18;
	deq1.push_front(1);
	deq2.push_front(1);
	for(int le=0,r=0;le<=n;le++)
	{
		while(!deq1.empty()&&deq1.front()<le) deq1.pop_front();
		while(!deq2.empty()&&deq2.front()<le) deq2.pop_front();
		while(a[deq1.front()].second-a[deq2.front()].second<d&&r<n)
		{
			r++;
			while(!deq1.empty()&&a[r].second>a[deq1.back()].second) deq1.pop_back();
			deq1.push_back(r);
			while(!deq2.empty()&&a[r].second<a[deq2.back()].second) deq2.pop_back();
			deq2.push_back(r);
		}
		if(r!=n) ans=min(ans,a[r].first-a[le].first);
		//or
		//if(a[q1.front()].second-a[q2.front()].second>=d) ans=min(ans,a[r].first-a[l].first);
	}
	if(ans==1e18) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}