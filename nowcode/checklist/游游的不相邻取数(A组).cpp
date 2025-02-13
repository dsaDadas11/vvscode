/*
 * @Author: HuangCe
 * @Date: 2025-02-13 13:10:41
 * @LastEditTime: 2025-02-13 13:17:18
 * @Description: go for it!
 */
// URL: https://ac.nowcoder.com/acm/contest/98215/H
/*
 解题思路：
 这道题要找的是取不相邻数的乘积，使末尾 0的个数最大
 那么就是求最后 2和 5的最小值
 这种题贪心一眼没办法做，那么只能考虑 dp
 再看每个位置有 取和不取两种情况，并且要看因子的个数
 那么定义 dp状态:
 dp[i][0][j] 表示第 i位不取，且有 j个 5因子的 2因子个数
 dp[i][1][j] 表示第 i位取，且有 j个 5因子的 2因子个数
 那么有状态转移方程: (需要保证 dp[i-1][0][j]和 dp[i-1][1][j]不为 -1才能状态转移，否则没状态还转移啥)
 dp[i][0][j]=max(dp[i-1][0][j],dp[i-1][1][j])
 dp[i][1][j]=max(dp[i][1][j],dp[i-1][0][j-cnt5]+cnt2)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+2;
int n;
int a[M];
int dp[M][2][14*M];
int cnt2[M],cnt5[M];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,-1,sizeof dp);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int t=a[i];
        while(t%2==0)
        {
            t/=2;
            cnt2[i]++;
        }
        while(t%5==0)
        {
            t/=5;
            cnt5[i]++;
        }
        cnt+=cnt5[i];
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=cnt;j++)
        {
            if(dp[i-1][0][j]!=-1)
            {
                dp[i][0][j]=max(dp[i][0][j],dp[i-1][0][j]);
                dp[i][1][j+cnt5[i]]=max(dp[i][1][j+cnt5[i]],dp[i-1][0][j]+cnt2[i]);
            }
            if(dp[i-1][1][j]!=-1)
            {
                dp[i][0][j]=max(dp[i][0][j],dp[i-1][1][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++)
    {
        ans=max(ans,min(i,dp[n][0][i]));
        ans=max(ans,min(i,dp[n][1][i]));
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