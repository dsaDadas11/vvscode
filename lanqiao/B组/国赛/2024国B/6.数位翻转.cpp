/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 15:33:13
 * @LastEditTime: 2025-06-07 15:40:35
 * @Description: go for it!
 */
/*
 在 dp[i][j][0]=max(dp[i][j][0],max(dp[i-1][j][0],dp[i-1][j][1])+a[i])中
 dp[i-1][j][1] 的 j=0时不成立，没有这种情况，所以需要特判

 因此不选的状态转移方程可以写为：
 dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][0]+a[i]);
 if(j-1>=0) dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][1]+a[i]); // j为 0时不能反转

 也可以直接从 j=1开始遍历，0的时候初始化
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,m;
int a[M],b[M];
int dp[M][M][2];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        vector<int> v;
        while(x)
        {
            v.push_back(x&1);
            x>>=1;
        }
        reverse(v.begin(),v.end());
        int base=1;
        for(auto j:v)
        {
            if(j) b[i]+=base;
            base<<=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0][0]=dp[i-1][0][0]+a[i];
        for(int j=1;j<=m;j++)
        {
            dp[i][j][0]=max(dp[i][j][0],max(dp[i-1][j][0],dp[i-1][j][1])+a[i]);
            dp[i][j][1]=max(dp[i][j][1],max(dp[i-1][j-1][0],dp[i-1][j][1])+b[i]);
        }
    }
    int ans=max(dp[n][0][0],dp[n][0][1]);
    for(int j=1;j<=m;j++) ans=max({ans,dp[n][j][0],dp[n][j][1]});
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}