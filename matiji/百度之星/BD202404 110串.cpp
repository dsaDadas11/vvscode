/*
 * @Author: dsaDadas11
 * @Date: 2024-06-06 20:20:59
 * @LastEditTime: 2024-06-06 21:17:28
 * @Description: go for it!
 */
/*
解题思路：
1.首先想字符串的状态
  当该位为x时，可由前一位的哪些位置转移过来，或者可修改
  需要注意的是：如果最后一位为1，那么只能是01，如果是11的话就是dp[i][j][2]了
2.dp只需要此位和前一位的状态即可，所以只需要记录 i%2(当前位置) 和 (i%2)^1(前一位)
  所以不需要开 N，可以节省空间
3.记得初始化dp[0][0][0]，即一开始的位置在0次修改时最后一位为0的时候答案个数为1
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e3+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n,k;
int dp[2][N][3]; // 0表示最后一位为0  1表示最后一位为1  2表示最后两位为11
string s;
void solve()
{
	cin>>n>>k;
	cin>>s;
	s=' '+s;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		// 这个位置的状态
		int l=i%2;
		// 前一个位置的状态
		int fro=(l?0:1);
		// 操作次数
		for(int j=0;j<=k;j++)
		{
			if(s[i]=='1') // 1
			{
				// 改变
				if(j>=1) dp[l][j][0]=(dp[l][j][0]+dp[fro][j-1][1]+dp[fro][j-1][0])%mod;
				// 不改变
				dp[l][j][1]=(dp[l][j][1]+dp[fro][j][0])%mod;
				dp[l][j][2]=(dp[l][j][2]+dp[fro][j][1]+dp[fro][j][2])%mod;
			}
			else // 0
			{
				// 改变
				if(j>=1)
				{
					dp[l][j][1]=(dp[l][j][1]+dp[fro][j-1][0])%mod;
					dp[l][j][2]=(dp[l][j][2]+dp[fro][j-1][1]+dp[fro][j-1][2])%mod;
				}
				// 不改变
				dp[l][j][0]=(dp[l][j][0]+dp[fro][j][1]+dp[fro][j][0])%mod;
			}
		}
		memset(dp[fro],0,sizeof dp[fro]);
	}
	int ans=0;
	for(int i=0;i<=k;i++)
	{
		ans=(ans+dp[n%2][i][0]+dp[n%2][i][1]+dp[n%2][i][2])%mod;
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