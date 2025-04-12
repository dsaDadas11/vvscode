/*
 * @Author: HuangCe
 * @Date: 2025-02-19 13:14:03
 * @LastEditTime: 2025-02-19 13:16:33
 * @Description: go for it!
 */
/*
 解题思路：
 这道题要用到多维 vis，因为每个点可以被不同的状态访问到
 因此我们将 vis开到四维，分别表示 x,y坐标、表示第几个 A或 B、表示 A还是 B
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int dx[7]={0,1,0,-1};
int dy[7]={1,0,-1,0};
int n,m,k;
char a[M][M];
int ans=-1;
struct op
{
    int x,y,stp;
};
bool check(int x,int y)
{
    if(x<1||x>n||y<1||y>m)  return 0;
    return 1;
}
int vis[M][M][13][2];
void bfs()
{
    queue<op > q;
    q.push({1,1,0});
    char ch;
    int kk,round;
    while(!q.empty())
    {
        auto [x,y,stp]=q.front();
        q.pop();
        kk=stp%k;
        if(kk==0) kk=k;
        round=(stp/k)%2;
        if(vis[x][y][kk][round]) continue;
        vis[x][y][kk][round]++;
        if(x==n&&y==m)
        {
            ans=max(ans,stp);
            return;
        }
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(((stp+1)/k)%2) ch='B';
            else ch='A';
            if(check(xx,yy)&&a[xx][yy]==ch)
            {
                q.push({xx,yy,stp+1});
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    bfs();
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}