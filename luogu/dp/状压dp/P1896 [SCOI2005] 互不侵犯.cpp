/*
 * @Author: dsaDadas11
 * @Date: 2025-05-12 19:49:31
 * @LastEditTime: 2025-05-12 19:50:22
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int dp[13][90][1<<10];
int num[1<<10]; // 记录状态中有多少个 1
bool check(int a,int b)
{
    return (a&b)||(a&(b<<1))||(a&(b>>1));
}
void solve()
{
    cin>>n>>k;
    vector<int> s; // 可行的状态
    for(int i=0;i<(1<<n);i++)
    {
        if(i&(i>>1)) continue;
        s.push_back(i);
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1) num[i]++;
        }
    }

    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(auto a:s)
            {
                for(auto b:s)
                {
                    if(check(a,b)) continue;
                    int c=num[a];
                    if(j>=c) dp[i][j][a]+=dp[i-1][j-c][b];
                }
            }
        }
    }
    int ans=0;
    for(auto a:s) ans+=dp[n][k][a];
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}