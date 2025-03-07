/*
 * @Author: dsaDadas11
 * @Date: 2025-03-04 21:45:26
 * @LastEditTime: 2025-03-04 22:00:03
 * @Description: go for it!
 */
// URL: https://www.lanqiao.cn/problems/1447/learning/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int w[107];
bool dp[107][N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=100000;j++)
        {
            dp[i][j]=dp[i-1][j]|dp[i-1][abs(j-w[i])]|dp[i-1][j+w[i]];
        }
    }
    int ans=0;
    for(int i=1;i<=100000;i++)
    {
        if(dp[n][i]) ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}