/*
 * @Author: dsaDadas11
 * @Date: 2025-03-04 18:47:00
 * @LastEditTime: 2025-03-04 18:47:15
 * @Description: go for it!
 */
// URL: https://www.lanqiao.cn/problems/1507/learning/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string a,b;
int dp[M][M];
void solve()
{
    cin>>a>>b;
    int n=a.size(),m=b.size();
    a=' '+a,b=' '+b;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int i=1;i<=m;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
        }
    }
    cout<<dp[n][m]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}