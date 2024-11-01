/*
 * @Author: dsaDadas11
 * @Date: 2024-10-05 15:42:28
 * @LastEditTime: 2024-10-05 19:29:52
 * @Description: go for it!
 */
/*
 解题思路：
 一开始把第ri天的所有优惠wi记录下来，
 然后用优先队列维护ri天之前最小的a[i]，
 然后再把所有的优惠加给a[i]就可以了，
 最后取数就是慢慢从堆头取出
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
int a[N],val[N];
priority_queue<int,vector<int>,greater<int> > pq;
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++) val[i]=0;
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n;i++) cin>>a[i];
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		val[x]+=y;
	}
	for(int i=1;i<=n;i++)
	{
		pq.push(a[i]);
		int xx=pq.top();
		pq.pop();
		xx-=val[i];
		pq.push(xx);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=pq.top();
		pq.pop();
		cout<<sum<<' ';
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