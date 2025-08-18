/*
 * @Author: dsaDadas11
 * @Date: 2025-08-13 16:40:06
 * @LastEditTime: 2025-08-13 16:40:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s;
int dp[57][57];
void solve()
{
    cin>>s;
    n=s.size();
    s=' '+s;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++) dp[i][i]=1;

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            if(s[i]==s[j])
            {
                dp[i][j]=dp[i][j-1];
                continue;
            }
            dp[i][j]=j-i+1;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}