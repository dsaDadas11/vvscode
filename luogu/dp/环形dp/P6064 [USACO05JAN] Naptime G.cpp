/*
 * @Author: dsaDadas11
 * @Date: 2025-08-15 15:29:37
 * @LastEditTime: 2025-08-15 15:29:49
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=4e3+7;
int dp[M][M][2];
// 前 i个小时睡了 j个小时，0没睡，1在睡
int n,b;
int u[M];
void solve()
{
    cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>u[i];
    memset(dp,-0x3f,sizeof dp);
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i][0][0]=dp[i-1][0][0];
        for(int j=1;j<=b;j++)
        {
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
            dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j-1][1]+u[i]);
        }
    }
    int ans=max(dp[n][b][0],dp[n][b][1]);

    memset(dp,-0x3f,sizeof dp);
    dp[1][0][0]=0,dp[1][1][1]=u[1];
    for(int i=2;i<=n;i++)
    {
        dp[i][0][0]=dp[i-1][0][0];
        for(int j=1;j<=b;j++)
        {
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
            dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j-1][1]+u[i]);
        }
    }
    ans=max(ans,dp[n][b][1]);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}