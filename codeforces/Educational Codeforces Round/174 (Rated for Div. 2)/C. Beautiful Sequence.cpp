/*
 * @Author: dsaDadas11
 * @Date: 2025-03-09 11:24:22
 * @LastEditTime: 2025-03-09 11:30:13
 * @Description: go for it!
 */
/*
 需要注意 dp[2]是双倍贡献
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
int a[N];
int dp[4];
void solve()
{
    memset(dp,0,sizeof dp);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==3) dp[3]=(dp[3]+dp[2])%mod;
        else if(a[i]==2) dp[2]=(dp[2]*2+dp[1])%mod;
        else dp[1]++;
    }
    cout<<dp[3]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}