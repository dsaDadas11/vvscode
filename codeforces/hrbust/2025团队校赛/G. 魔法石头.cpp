/*
 * @Author: dsaDadas11
 * @Date: 2025-04-13 19:01:27
 * @LastEditTime: 2025-04-13 19:01:50
 * @Description: go for it!
 */
/*
 纯纯诈骗题
 模完之后的是真的价值，比如 1e9+8 变为 1，那么价值就是 1不是 1e9+8
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e18;
constexpr int mod=1e9+7;
int n;
int a[107];
int dp[107][107],val[107][107];
void solve()
{
    cin>>n;
    memset(dp,0,sizeof dp);
    memset(val,0,sizeof val);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        val[i][i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int pre=1;
        for(int j=i;j<=n;j++)
        {
            pre*=(a[j]+1);
            pre%=mod;
            val[i][j]=pre-1;
            val[i][j]=(val[i][j]+mod)%mod;
        }
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            dp[i][j]=inf;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+val[i][k]+val[k+1][j]);
            }
        }
    }
    cout<<dp[1][n]<<' '<<val[1][n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}