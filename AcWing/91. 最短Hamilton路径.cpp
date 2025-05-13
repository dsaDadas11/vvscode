/*
 * @Author: dsaDadas11
 * @Date: 2025-05-12 18:55:29
 * @LastEditTime: 2025-05-12 18:55:44
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=2e6+7;
constexpr int M=2e3+7;
int n;
int dist[23][23];
int dp[N][23];
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dist[i][j];
        }
    }
    memset(dp,0x3f,sizeof dp);
    dp[1][0]=0;
    for(int S=0;S<(1<<n);S++)
    {
        for(int j=0;j<n;j++)
        {
            if(S&(1<<j))
            {
                for(int k=0;k<n;k++)
                {
                    if(((S^(1<<j))>>k)&1)
                    {
                        dp[S][j]=min(dp[S][j],dp[S^(1<<j)][k]+dist[k][j]);
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}