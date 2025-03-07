/*
 * @Author: dsaDadas11
 * @Date: 2025-03-04 21:59:30
 * @LastEditTime: 2025-03-04 21:59:50
 * @Description: go for it!
 */
// URL: https://www.lanqiao.cn/problems/505/learning/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[107][107];
int dp[107][107];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
        }
    }
    if(n&1) cout<<dp[n][n/2+1]<<endl;
    else cout<<max(dp[n][n/2],dp[n][n/2+1])<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}