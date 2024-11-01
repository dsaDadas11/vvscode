/*
 * @Author: dsaDadas11
 * @Date: 2024-10-31 22:25:41
 * @LastEditTime: 2024-10-31 22:48:58
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/P1044
/*
 解题思路：
 这道题不能直接暴力，要用记忆化搜索递归(可以写递推)
 首先设数组 dp[i][j] 为i个数要入栈 j个数在栈内
 如果 i=0 那就只有一种方法了 return 1
 更普遍的情况分为两种操作 1.入栈 2.出栈
 那么状态转移方程为 dp[i][j]+=dfs(x-1,y+1)+dfs(x,y-1)
 注意,这里是从左边的状态转为右边的状态
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
//  还有多少个数要入栈  多少个数在栈内
int dp[57][57];
int dfs(int x,int y)
{
	if(y<0) return 0;
	if(dp[x][y]) return dp[x][y];
	if(x==0) return 1;
	dp[x][y]+=dfs(x-1,y+1)+dfs(x,y-1);
	return dp[x][y];
}
void solve()
{
	cin>>n;
	cout<<dfs(n,0)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
//  还有多少个数要入栈  多少个数出栈
int dp[57][57];
void solve()
{
	cin>>n;
	for(int i=0;i<=n;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[n][n]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}



#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
//  还有多少个数要入栈  多少个数在栈中
int dp[57][57];
void solve()
{
	cin>>n;
	for(int i=0;i<=n;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
            //注意是从左往右转移
			if(j==0) dp[i][j]+=dp[i-1][j+1];
			else dp[i][j]+=dp[i][j-1]+dp[i-1][j+1];
		}
	}
	cout<<dp[n][0]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/