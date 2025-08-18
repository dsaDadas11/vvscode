/*
 * @Author: dsaDadas11
 * @Date: 2025-08-07 11:53:40
 * @LastEditTime: 2025-08-07 11:58:52
 * @Description: go for it!
 */
/*
 主要是面怎么处理
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=5e2+7;
constexpr int inf=1e9;
int n;
int a[M][M],dp[M][M];
bool vis[M][M];
int tx,ty;
struct face
{
    int u,d,l,r;
}f[9]={
{0, 0, 0, 0},
{-1, 3, 4, 2}, {-1, 4, 3, 1}, {-1, 1, 2, 4}, {-1, 2, 1, 3},
{3, -1, 2, 4}, {4, -1, 1, 3}, {1, -1, 4, 2}, {2, -1, 3, 1}
};
void bfs()
{
    queue<pair<int,int> > q;
    q.push({1,1});
    dp[1][1]=0;
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y]=1;
        if(y&1)
        {
            face t=f[a[x][y]];
            if(a[x][y-1]==t.l)
            {
                dp[x][y-1]=min(dp[x][y-1],dp[x][y]+1);
                q.push({x,y-1});
            }
            if(a[x][y+1]==t.r)
            {
                dp[x][y+1]=min(dp[x][y+1],dp[x][y]+1);
                q.push({x,y+1});
            }
            if(a[x-1][y-1]==t.u)
            {
                dp[x-1][y-1]=min(dp[x-1][y-1],dp[x][y]+1);
                q.push({x-1,y-1});
            }
            if(a[x+1][y+1]==t.d)
            {
                dp[x+1][y+1]=min(dp[x+1][y+1],dp[x][y]+1);
                q.push({x+1,y+1});
            }
        }
        else
        {
            face t=f[a[x][y]+4];
            if(a[x][y-1]==t.l)
            {
                dp[x][y-1]=min(dp[x][y-1],dp[x][y]+1);
                q.push({x,y-1});
            }
            if(a[x][y+1]==t.r)
            {
                dp[x][y+1]=min(dp[x][y+1],dp[x][y]+1);
                q.push({x,y+1});
            }
            if(a[x-1][y-1]==t.u)
            {
                dp[x-1][y-1]=min(dp[x-1][y-1],dp[x][y]+1);
                q.push({x-1,y-1});
            }
            if(a[x+1][y+1]==t.d)
            {
                dp[x+1][y+1]=min(dp[x+1][y+1],dp[x][y]+1);
                q.push({x+1,y+1});
            }
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*i-1;j++)
        {
            cin>>a[i][j];
            dp[i][j]=inf;
        }
    }
    memset(dp,0x3f,sizeof dp);
    bfs();
    cin>>tx>>ty;
    if(dp[tx][ty]>=inf) cout<<"-1"<<endl;
    else cout<<dp[tx][ty]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}