/*
 * @Author: dsaDadas11
 * @Date: 2024-07-30 18:50:43
 * @LastEditTime: 2024-07-30 18:54:02
 * @Description: go for it!
 */
/*
 解题思路：
 1.首先找k个免费的物品(也就是找价值最大的前k个物品)用小根堆维护
 2.然后用dp更新每次的值，并加上后面i+1个免费物品的最值，然后更新ans
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=5e3+7;
int n,W,k;
pair<int,int> p[N];
int dp[N],g[N];
void solve()
{
	cin>>n>>W>>k;
	for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n);
	priority_queue<int,vector<int>,greater<int> > pq;
	int sum=0;
	for(int i=n;i>=1;i--)
	{
		sum+=p[i].second;
		pq.push(p[i].second);
		if((int)pq.size()>k)
		{
			sum-=pq.top();
			pq.pop();
		}
		g[i]=sum;
	}
	int ans=g[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=W;j>=p[i].first;j--)
		{
			dp[j]=max(dp[j],dp[j-p[i].first]+p[i].second);
			ans=max(ans,dp[j]+g[i+1]);
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}