/*
 * @Author: dsaDadas11
 * @Date: 2025-05-12 20:25:17
 * @LastEditTime: 2025-05-12 20:25:37
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e8;
int n,m;
int dp[17][1<<13];
vector<int> s[17];
int t[17];
void solve()
{
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            t[i]=(t[i]<<1)+1-x;
        }

        for(int j=0;j<(1<<m);j++)
        {
            if((j&(j<<1))||(t[i]&j)) continue;
            s[i].push_back(j);
        }
    }

    // 预处理第一行
    for(auto a:s[1]) dp[1][a]=1;
    for(int i=2;i<=n;i++)
    {
        for(auto a:s[i])
        {
            for(auto b:s[i-1])
            {
                if(a&b) continue;
                dp[i][a]=(dp[i][a]+dp[i-1][b])%mod;
            }
        }
    }

    int ans=0;
    for(auto a:s[n])
    {
        ans=(ans+dp[n][a])%mod;
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