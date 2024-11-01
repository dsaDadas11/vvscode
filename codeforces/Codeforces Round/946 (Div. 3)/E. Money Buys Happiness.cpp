/*
 * @Author: dsaDadas11
 * @Date: 2024-09-25 21:01:37
 * @LastEditTime: 2024-09-26 11:55:01
 * @Description: go for it!
 */
/*
 解题思路：
 我们看h的范围1e3，挺小的，可以直接设h为状态
 设dp[j]为获取j快乐值还剩的最大费用
 那么就有状态转移方程： if(dp[j-h[i]]-c[i]>=0) dp[j]=max(dp[j],dp[j-h[i]]-c[i]);
 我们想想怎么初始化
 我们答案要找什么数呢？应该是dp[j]>=0的最大数
 那么我们不能将dp初始化为0，而应该为-1，但是dp[0]=0 (获取0快乐值不需要费用)
 然后还需要将不是-1的状态加上x，因为这些状态在后面的月还能转化为更高的状态(一开始以为从0转就行...)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int m,x;
int c[57],h[57];
int dp[N];
void solve()
{
	cin>>m>>x;
	int hh=0;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i]>>h[i];
		hh+=h[i];
	}
	for(int i=0;i<=hh;i++) dp[i]=-1;
	dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=hh;j>=h[i];j--)
		{
			if(dp[j-h[i]]-c[i]>=0)
			{
				dp[j]=max(dp[j],dp[j-h[i]]-c[i]);
			}
		}
		for(int j=0;j<=hh;j++)
		{
			if(dp[j]!=-1) dp[j]+=x;
		}
	}
	for(int i=hh;i>=0;i--)
	{
		if(dp[i]!=-1)
		{
			cout<<i<<endl;
			return;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}