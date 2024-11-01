/*
 * @Author: dsaDadas11
 * @Date: 2024-09-09 20:45:40
 * @LastEditTime: 2024-09-10 13:49:20
 * @Description: go for it!
 */
/*
 一个典型的区间dp，看完例题就知道这道题的大概思路了
 我们定义一个三维dp[now][l][r] 表示：当前s的位置 s匹配t[l,r]的方案数 // 三维更好写，二维写了一天都写不出来
 这道题和模板题不同的是
 1.si=si+ai+si这一步，会方案数加倍
 2.s[i]==t[k+1]这一步，需要将当前步骤的方案数+1 //思考一下，为什么k从l-1到r-1 而不是从l到r
 3.判断一下边界
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
string s,t;
int dp[107][107][107];
void solve()
{
	cin>>s>>t;
	int lens=s.size(),lent=t.size();
	s=' '+s,t=' '+t;
	for(int now=1;now<=lens;now++)
	{
		for(int l=1;l<=lent;l++)
		{
			for(int r=l;r<=lent;r++)
			{
				for(int k=l;k<r;k++)
				{
					dp[now][l][r]=(dp[now][l][r]+(dp[now-1][l][k]*dp[now-1][k+1][r])%mod)%mod;
				}
				for(int k=l-1;k<r;k++)
				{
					if(s[now]!=t[k+1]) continue;
					if(l==r) dp[now][l][r]=(dp[now][l][r]+1)%mod;
					else if(k==l-1) dp[now][l][r]=(dp[now][l][r]+dp[now-1][k+2][r])%mod;
					else if(k==r-1) dp[now][l][r]=(dp[now][l][r]+dp[now-1][l][k])%mod;
					else dp[now][l][r]=(dp[now][l][r]+(dp[now-1][l][k]*dp[now-1][k+2][r])%mod)%mod;
				}
			}
		}
		for(int i=1;i<=lent;i++)
		{
			for(int j=i;j<=lent;j++)
			{
				dp[now][i][j]=(dp[now][i][j]+(2*dp[now-1][i][j])%mod)%mod;
			}
		}
	}
	cout<<dp[lens][1][lent]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}