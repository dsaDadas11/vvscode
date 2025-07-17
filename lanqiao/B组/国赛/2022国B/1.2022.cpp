/*
 * @Author: dsaDadas11
 * @Date: 2025-06-11 11:13:37
 * @LastEditTime: 2025-06-11 11:13:45
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dp[2023][11][2023]; // 第 i个数  选 j个  得 k个
void solve()
{
    for(int i=0;i<=2022;i++) dp[i][0][0]=1;

    for(int i=1;i<=2022;i++)
    {
        for(int j=1;j<=10;j++)
        {
            for(int k=1;k<=2022;k++)
            {
                dp[i][j][k]=dp[i-1][j][k];
                if(k>=i) dp[i][j][k]+=dp[i-1][j-1][k-i];
            }
        }
    }
    cout<<dp[2022][10][2022];
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}