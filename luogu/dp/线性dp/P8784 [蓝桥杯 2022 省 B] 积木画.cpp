/*
 * @Author: dsaDadas11
 * @Date: 2025-03-05 12:35:32
 * @LastEditTime: 2025-03-05 12:35:43
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n;
int dp[N];
void solve()
{
    cin>>n;
    dp[1]=1,dp[2]=2,dp[3]=5;
    for(int i=4;i<=n;i++)
    {
        dp[i]=(dp[i-1]*2%mod+dp[i-3])%mod;
    }
    cout<<dp[n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}