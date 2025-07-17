/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 18:02:54
 * @LastEditTime: 2025-06-07 18:03:05
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int c[N];
set<int> dp[N];
set<int> dfs(int x)
{
    if(x>n) return {};
    if(dp[x].size()) return dp[x];
    set<int> se;
    if(x+c[x]<=n)
    {
        set<int> tmp=dfs(x+c[x]);
        for(auto i:tmp) se.insert(i);
    }
    if(2*x<=n)
    {
        set<int> tmp=dfs(x*2);
        for(auto i:tmp) se.insert(i);
    }
    se.insert(c[x]);
    dp[x]=se;
    return dp[x];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(int)dfs(i).size());
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