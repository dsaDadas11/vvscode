/*
 * @Author: dsaDadas11
 * @Date: 2025-08-23 11:27:03
 * @LastEditTime: 2025-08-23 11:39:13
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
int n;
int a[307];
int dp[307][307];
int s[307];
int p[307][307];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i],p[i][i]=i;
    }

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            dp[i][j]=inf; // 注意需要初始化为正无穷
            for(int k=p[i][j-1];k<=p[i+1][j];k++)
            {
                if(dp[i][j]>dp[i][k]+dp[k+1][j]+s[j]-s[i-1])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+s[j]-s[i-1];
                    p[i][j]=k;
                }
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