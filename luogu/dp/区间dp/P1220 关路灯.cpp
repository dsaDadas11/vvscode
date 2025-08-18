/*
 * @Author: dsaDadas11
 * @Date: 2025-08-13 16:10:46
 * @LastEditTime: 2025-08-13 16:12:46
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e16;
int n,c;
struct op
{
    int x,w;
}a[57];
// dp[0][i][j] 表示目前处于 i位置
// dp[1][i][j] 表示目前处于 j位置
int dp[2][57][57];
int sum[57];
void solve()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].w;
        sum[i]=sum[i-1]+a[i].w;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[0][i][j]=dp[1][i][j]=inf;
        }
    }

    dp[0][c][c]=dp[1][c][c]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i+k<=n;i++)
        {
            int j=i+k;
            int w1=sum[n]-(sum[j]-sum[i]); // [i+1,j]的灯已经关了，他们的功率产生不了贡献
            dp[0][i][j]=min(dp[0][i+1][j]+w1*(a[i+1].x-a[i].x),dp[1][i+1][j]+w1*(a[j].x-a[i].x));
            int w2=sum[n]-(sum[j-1]-sum[i-1]); // [i,j-1]的灯已经关了，他们的功率产生不了贡献
            dp[1][i][j]=min(dp[0][i][j-1]+w2*(a[j].x-a[i].x),dp[1][i][j-1]+w2*(a[j].x-a[j-1].x));
        }
    }
    cout<<min(dp[0][1][n],dp[1][1][n])<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}