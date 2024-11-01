/*
 * @Author: dsaDadas11
 * @Date: 2024-09-20 20:32:07
 * @LastEditTime: 2024-09-20 20:41:03
 * @Description: go for it!
 */
/*
 解题思路：
 设一段序列在S上匹配的区间为[L,R](L,R均为最左端和最右端)，那么这段序列对整个S串的贡献即为L*(n-R+1)
 我们只需要求L的长度和即可
 我们设dp[i][j][k]表示的是S的前i位匹配s1的前j位和s2的前k位的方案数 (似乎是匹配s1前j位的方案数与匹配s2前k位的方案数的乘积)
 那么总方案数就是dp[i][len1][len2]的和
 ans+=dp[i][len1][len2]*(n-i+1)
 难点来了，状态转移方程是什么? 如何前缀和前i-1位的j,k
 首先我们看dp[i][0][0]的方案数有多少，肯定是i种了，那么每回算到这种状态时都需要+i
 其余的看代码吧
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int dp[N][27][27];
int sum[27][27];
string s,s1,s2;
void solve()
{
	cin>>s>>s1>>s2;
	int len=s.size(),len1=s1.size(),len2=s2.size();
	s=' '+s,s1=' '+s1,s2=' '+s2;
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<=len1;j++)
		{
			for(int k=0;k<=len2;k++)
			{
				if(s[i]==s1[j])
				{
					dp[i][j][k]=(dp[i][j][k]+(sum[j-1][k]+(j==1&&k==0)*i)%mod)%mod;;
				}
				if(s[i]==s2[k])
				{
					dp[i][j][k]=(dp[i][j][k]+(sum[j][k-1]+(j==0&&k==1)*i)%mod)%mod;
				}
				if(s[i]==s1[j]&&s[i]==s2[k])
				{
					dp[i][j][k]=(dp[i][j][k]+(sum[j-1][k-1]+(j==0&&k==0)*i)%mod)%mod;
				}
			}
		}
		for(int j=0;j<=len1;j++)
		{
			for(int k=0;k<=len2;k++)
			{
				sum[j][k]=(sum[j][k]+dp[i][j][k])%mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=len;i++)
	{
		ans+=(dp[i][len1][len2]*(len-i+1))%mod;
		ans%=mod;
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