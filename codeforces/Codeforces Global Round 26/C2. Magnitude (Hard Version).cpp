/*
 * @Author: dsaDadas11
 * @Date: 2024-11-07 13:59:16
 * @LastEditTime: 2024-11-07 14:01:52
 * @Description: go for it!
 */
/*
 解题思路：
 在前一个问题中，我们算出了最大值，
 那么我们可以遍历1-n中哪一些等于这个最大值，
 如果等于的话，i前面的大于等于0的个数可以使用操作1，2，i后面都可以使用操作1，2，但是第i位只能用操作2
 那么答案为 ans+=quickpow(2,n-i+cnt[i-1])
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
int a[N];
int sum[N],suf[N],cnt[N];
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=(ans*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=0;i<=n+5;i++) cnt[i]=sum[i]=suf[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		if(sum[i]>=0) cnt[i]=cnt[i-1]+1;
		else cnt[i]=cnt[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,abs(sum[i])+suf[i+1]);
	}
	int ans=0;
	if(cnt[n]==n)
	{
		cout<<quickpow(2,n)<<endl;
		return;
	}
	int t=0;
	for(int i=1;i<=n;i++)
	{
		t=abs(sum[i])+suf[i+1];
		if(t==maxn)
		{
			ans+=quickpow(2,n-i+cnt[i-1]);
			ans%=mod;
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