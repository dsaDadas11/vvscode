/*
 * @Author: dsaDadas11
 * @Date: 2025-05-04 12:11:46
 * @LastEditTime: 2025-05-04 12:12:17
 * @Description: go for it!
 */
/*
 解题思路：
 不知道为什么我的 bfs常数这么大....优化好多次才过
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
#define pll pair<int,int>
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[7]={0,1,0,-1};
int dy[7]={1,0,-1,0};
int m;
int ans[3]; // 1白 2黑
int col[20][20];
bool vis[20][20];
bool check(int x,int y)
{
    return x>=1&&x<=19&&y>=1&&y<=19;
}
void find_chess(int x,int y,int ord) // 找联通块并且判定是否被围住
{
    queue<pll> q;
    q.push({x,y});
    vector<pll> p;
    vis[x][y]=1;
    bool ok=0;
    while(!q.empty())
    {
        auto &[x,y]=q.front();
        q.pop();
        p.emplace_back(x,y);
        for(int k=0;k<4;k++)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(!check(xx,yy)||vis[xx][yy]) continue;
            if(col[xx][yy]==0) ok=1;
            if(col[xx][yy]!=ord) continue;
            q.push({xx,yy});
            vis[xx][yy]=1; // 只能标记同类型棋子，不能标记空位，会导致 bfs中下一次判断不到空位
        }
    }
    if(ok) return;

    ans[ord]+=p.size();
    for(auto &[x,y]:p)
    {
        col[x][y]=0; // 移走棋子
    }
}
void bfs(int ord,vector<pll> &p) // 判断黑白
{
    ans[1]=ans[2]=0;
    memset(vis,0,sizeof vis);
    // 先移除对立棋子
    for(auto &[x,y]:p)
    {
        if(vis[x][y]) continue;
        if(col[x][y]==3-ord) find_chess(x,y,3-ord);
    }

    // 移除本棋子
    memset(vis,0,sizeof vis);
    for(auto &[x,y]:p)
    {
        if(vis[x][y]) continue;
        if(col[x][y]==ord) find_chess(x,y,ord);
    }

    cout<<ans[2]<<' '<<ans[1]<<endl;
}
void solve()
{
    cin>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        int round=i&1; // 0白 1黑
        round++;
        col[x][y]=round;
        vector<pll> p; // 每次只需判断包括自身的周围五个位置
        p.emplace_back(x,y);
        for(int k=0;k<4;k++)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(!check(xx,yy)) continue;
            p.emplace_back(xx,yy);
        }
        bfs(round,p);
    }    
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}