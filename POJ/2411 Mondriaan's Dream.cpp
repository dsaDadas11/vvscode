/*
 * @Author: dsaDadas11
 * @Date: 2024-09-19 22:35:21
 * @LastEditTime: 2024-09-19 22:47:26
 * @Description: go for it!
 */
/*
 温馨提示：开long long
 这是一道状压dp典型题，我们将1定义为横放，0定义为竖放
 我们先枚举每个状态的合法性(注意这里不能预处理vis，因为每一组n的状态都是不一样的)
 首先不合法的为：在1之前有奇数个0 (竖着放的肯定是偶数个位置)
 然后就枚举这列和前一列是否相融合（1重叠或者被vis标记了）
*/
#include<iostream>
#include<cstring>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=3e3+7;
int n,m;
bool vis[M];
int dp[17][M];
void solve()
{
	for(int i=0;i<1<<n;i++)
	{
		vis[i]=1;
		int cnt=0; // 记录0有多少个
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				if(cnt&1) // 奇数个0不合法
				{
					vis[i]=0;
					break;
				}
			}
			else cnt++;
		}
		if(cnt&1) vis[i]=0;
	}

	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	int len=(1<<n);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<len;j++) // 这一个状态的
		{
			for(int k=0;k<len;k++) // 上一个状态的
			{
				// 1不能重叠 奇数个0
				if((j&k)==0&&vis[j|k])
				{
					dp[i][j]+=dp[i-1][k];
				}
			}
		}
	}
	cout<<dp[m][0]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(cin>>n>>m&&(n||m)){solve();}
	return 0;
}

/*
 滚动数组写法(注意清空dp[now])
    dp[0][0]=1;
	int len=(1<<n);
	int now=0,pre=1;
	for(int i=1;i<=m;i++)
	{
		swap(now,pre);
		memset(dp[now],0,sizeof dp[now]);
		for(int j=0;j<len;j++) // 这一个状态的
		{
			for(int k=0;k<len;k++) // 上一个状态的
			{
				// 1不能重叠 奇数个0
				if((j&k)==0&&vis[j|k])
				{
					dp[now][j]+=dp[pre][k];
				}
			}
		}
	}
	cout<<dp[now][0]<<endl;
*/