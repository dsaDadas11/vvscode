/*
 * @Author: dsaDadas11
 * @Date: 2024-10-05 20:36:09
 * @LastEditTime: 2024-10-05 21:39:02
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
int dp[N];
int dfs(int x)
{
    if(x<=0) return 0;
    if(dp[x]) return dp[x];
    dp[x]+=dfs(x-1)+dfs(x-k+1);
    return dp[x];
}
void solve()
{
    cin>>n>>k;
    for(int i=0;i<=n+5;i++) dp[i]=0;
    for(int i=1;i<k;i++) dp[i]=1;
    cout<<dfs(n)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}