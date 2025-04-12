/*
 * @Author: dsaDadas11
 * @Date: 2025-03-28 19:43:45
 * @LastEditTime: 2025-03-28 19:44:25
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
void solve()
{
    cin>>n>>k;
    int x;
    vector<vector<int> > a(n+5,vector<int>(k+5));
    vector<vector<int> > dp(n+5,vector<int>(k+5));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
        }
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++) ans=max(ans,dp[n][k]);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}