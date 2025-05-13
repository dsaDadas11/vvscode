/*
 * @Author: dsaDadas11
 * @Date: 2025-04-25 19:12:02
 * @LastEditTime: 2025-04-25 19:12:13
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[7]={0,-1,0,1};
int dy[7]={1,0,-1,0};
int n,m;
bool a[507][507];
bool vis[507][507];
bool check(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}
struct op
{
    int x,y,stp;
};
void bfs()
{
    queue<op> q;
    for(int i=1;i<=n;i++)
    {
        if(a[i][1]) q.push({i,1,1});
    }
    while(!q.empty())
    {
        auto [x,y,stp]=q.front();
        q.pop();
        if(y==m)
        {
            cout<<stp<<endl;
            return;
        }
        if(vis[x][y]) continue;
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(check(xx,yy)&&a[xx][yy]) q.push({xx,yy,stp+1});
        }

    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=1;
            vis[i][j]=0;
        }
    }
    int r,x;
    for(int i=1;i<=n;i++)
    {
        cin>>r;
        for(int j=1;j<=r;j++)
        {
            cin>>x;
            a[i][x]=0;
        }
    }
    bfs();
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}