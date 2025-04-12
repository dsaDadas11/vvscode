/*
 * @Author: dsaDadas11
 * @Date: 2025-04-05 19:58:26
 * @LastEditTime: 2025-04-05 19:58:47
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int n;
int a[N],pre[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	int ans=1e16;
	int sum;
	multiset<int> se;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			se.insert(pre[j]-pre[i-1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum=pre[j]-pre[i-1];
			se.erase(se.find(sum));
			auto it=se.lower_bound(sum);
			ans=min(ans,abs(sum-*it));
			if(it!=se.begin()) it--;
			ans=min(ans,abs(sum-*it));
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