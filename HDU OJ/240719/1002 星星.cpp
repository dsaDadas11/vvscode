/*
 * @Author: dsaDadas11
 * @Date: 2024-07-19 15:11:17
 * @LastEditTime: 2024-07-21 10:40:35
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=4e3+7;
int dp[N][M];
void solve()
{
	int n,k;
	cin>>n>>k;
	int a,b,c,d;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j]=1e18;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c>>d;
		for (int j=0;j<=k;j++)
		{
			dp[i][j]=min(dp[i][j],dp[i-1][j]);
			if (j>=1) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a);
			if (j>=2) dp[i][j]=min(dp[i][j],dp[i-1][j-2]+b);
			if (j>=3) dp[i][j]=min(dp[i][j],dp[i-1][j-3]+c);
			if (j>=4) dp[i][j]=min(dp[i][j],dp[i-1][j-4]+d);
		}
	}
	cout<<dp[n][k]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*

一维数组的代码试图通过使用一维DP数组 dp[k] 而不是二维数组来压缩空间复杂度。但是，它没有正确处理状态转移。
主要问题是，在同一轮迭代中，直接就地更新 dp 数组会导致错误的结果，因为每次更新会影响后续的更新。
***上面是值得注意的一点

为了纠正空间优化代码，使用一个临时数组来存储当前轮次的DP更新值。
这确保了每轮的所有更新都基于上一轮的值，保持正确的状态转移。

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=4e3+7;
int dp[M], temp[M];
void solve() {
	int n, k;
	cin >> n >> k;
	int a, b, c, d;
	fill(dp, dp + k + 1, 1e18);  // 初始化dp数组为无穷大
	dp[0] = 0;  // 0代价获得0颗星星
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c >> d;
		copy(dp, dp + k + 1, temp);  // 将当前dp状态复制到temp数组
		for (int j = 0; j <= k; j++) {
			if (j >= 1) temp[j] = min(temp[j], dp[j-1] + a);
			if (j >= 2) temp[j] = min(temp[j], dp[j-2] + b);
			if (j >= 3) temp[j] = min(temp[j], dp[j-3] + c);
			if (j >= 4) temp[j] = min(temp[j], dp[j-4] + d);
		}
		copy(temp, temp + k + 1, dp);  // 用新值更新dp数组
	}
	cout << dp[k] << endl;
}
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

滚动数组写法：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=4e3+7;
int dp[2][M];
int n,k,pos,pos2;
int a,b,c,d;
void solve()
{
	cin>>n>>k;
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c>>d;
		pos=i%2;
		pos2=pos^1;
		for(int j=0;j<=k;j++)
		{
			dp[pos][j]=dp[pos2][j]; //该轮可选可不选，所以要状态转移
			if(j>=1) dp[pos][j]=min(dp[pos][j],dp[pos2][j-1]+a);
			if(j>=2) dp[pos][j]=min(dp[pos][j],dp[pos2][j-2]+b);
			if(j>=3) dp[pos][j]=min(dp[pos][j],dp[pos2][j-3]+c);
			if(j>=4) dp[pos][j]=min(dp[pos][j],dp[pos2][j-4]+d);
		}
	}
	cout<<dp[n%2][k]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

*/