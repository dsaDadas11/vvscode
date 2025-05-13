/*
 * @Author: dsaDadas11
 * @Date: 2025-04-26 11:03:44
 * @LastEditTime: 2025-04-26 11:04:34
 * @Description: go for it!
 */
/*
 解题思路：
 互斥的多重背包，需要用滚动数组维护，防止取到组内不止一个物品
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=1e2+7;
int n,m,x;
int dp[M][N];
int w[M][M],val[M][M];
void solve()
{
    cin>>n>>m>>x;
    memset(dp,0,sizeof dp);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>w[i][j];
            cin>>val[i][j];
            w[i][j]+=w[i][j-1];
            val[i][j]+=val[i][j-1];
        }
        sum+=val[i][m];
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=x;k++) dp[i][k]=max(dp[i][k],dp[i-1][k]);
            for(int k=x;k>=w[i][j];k--)
            {
                dp[i][k]=max(dp[i][k],dp[i-1][k-w[i][j]]+val[i][j]);
            }
            for(int k=0;k<=x;k++) mx=max(mx,dp[i][k]);
        }
    }
    cout<<sum-mx<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}