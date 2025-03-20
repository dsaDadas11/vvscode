/*
 * @Author: dsaDadas11
 * @Date: 2025-03-08 11:32:17
 * @LastEditTime: 2025-03-08 11:35:08
 * @Description: go for it!
 */
/*
 解题思路：
 在普通的线性 dp情况下加上了"时间戳"
 但是到达 [x,y]点的时间永远是 x-1+y-1
 因此如果无法到达该点，就把 val[x][y]设置为无穷小 (即无法从这个状态进行状态转移)
 需要注意初始化
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
constexpr int inf=-1e16;
int n,m,t;
int x,y,v;
int a[M][M];
int dp[M][M];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=inf;
        }
    }
    dp[0][1]=dp[1][0]=0; // 初始化
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>x>>y>>v;
        if(x+y-2>=v) a[x][y]=inf;
    }
    int ans=a[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            ans=max(ans,dp[i][j]);
        }
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