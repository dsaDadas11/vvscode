/*
 * @Author: dsaDadas11
 * @Date: 2024-09-18 22:47:32
 * @LastEditTime: 2024-09-18 22:51:06
 * @Description: go for it!
 */
/*
 解题思路：
 这题有点像背包，但又不完全像
 我们可以设dp[a][b][c][d]表示1用了a张，2用了b张，3用了c张，4用了d张
 那么根据用的卡片数可以算出当前所在位置pos，但别忘了加1
 那么状态转移方程就可以写出了：
 if(a) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+val[x]);
 if(b) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+val[x]);
 if(c) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+val[x]);
 if(d) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+val[x]);
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,x; // 棋子格数  卡片数
int val[357];
int f[7]; // 卡片上的数字
int dp[47][47][47][47];
//     1    2  3   4 
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>val[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		f[x]++;
	}
	dp[0][0][0][0]=val[1];
	for(int a=0;a<=f[1];a++)
	{
		for(int b=0;b<=f[2];b++)
		{
			for(int c=0;c<=f[3];c++)
			{
				for(int d=0;d<=f[4];d++)
				{
					x=a*1+b*2+c*3+d*4+1;
					if(a) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+val[x]);
					if(b) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+val[x]);
					if(c) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+val[x]);
					if(d) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+val[x]);
				}
			}
		}
	}
	cout<<dp[f[1]][f[2]][f[3]][f[4]]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}