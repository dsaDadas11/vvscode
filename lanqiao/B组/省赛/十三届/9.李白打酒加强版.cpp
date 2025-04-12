/*
 * @Author: dsaDadas11
 * @Date: 2025-04-08 18:38:59
 * @LastEditTime: 2025-04-08 18:39:53
 * @Description: go for it!
 */
/*&
 解题思路：
 酒量的那一维不能超过 m，因为最后酒量为 0
 因此可以列三维 dp,用记忆化搜索更好实现
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n,m;
int dp[107][107][107];
int dfs(int sum,int x,int y)
{
    if(sum<0||x<0||y<0) return 0;
    if(sum>y) return 0;
    if(y==1) return sum==1&&x==0;
    if(dp[sum][x][y]!=-1) return dp[sum][x][y];
    return dp[sum][x][y]=(dfs(sum*2,x-1,y)+dfs(sum-1,x,y-1))%mod;
}
void solve()
{
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    cout<<dfs(2,n,m)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}