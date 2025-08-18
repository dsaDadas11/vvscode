/*
 * @Author: dsaDadas11
 * @Date: 2024-09-02 22:56:41
 * @LastEditTime: 2024-09-02 22:59:04
 * @Description: go for it!
 */
/*
 解题思路：
 这是一道多重背包题
 我们如果直接遍历的话复杂度是n*W*m，那么怎么降低时间复杂度呢？
 用二进制拆分，把m拆分成logm个二进制数，他们加一块可以凑成1-m个数，时间复杂度可以降低至n*W*logm
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,W;
int u[N],w[N],m[N];// 价值 重量 数量
int w1[N],n1,u1[N];
int dp[N];
void solve()
{
	cin>>n>>W;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>w[i]>>m[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		while(cnt<=m[i])
		{
			m[i]-=cnt;
			u1[++n1]=cnt*u[i];
			w1[n1]=cnt*w[i];
			cnt<<=1;
		}
		if(m[i]>0)
		{
			u1[++n1]=u[i]*m[i];
			w1[n1]=w[i]*m[i];
		}
	}
	for(int i=1;i<=n1;i++)
	{
		for(int j=W;j>=w1[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w1[i]]+u1[i]);
		}
	}
	cout<<dp[W]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}