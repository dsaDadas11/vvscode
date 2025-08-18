/*
 * @Author: dsaDadas11
 * @Date: 2025-08-12 10:18:53
 * @LastEditTime: 2025-08-12 15:56:36
 * @Description: go for it!
 */
/*
 解题思路；
 一个连通块里面，如果有一个赢家，那么整个连通块都是赢家，
 因为这个点可以通过连通块到达赢家的点
 然后我们暴力枚举每个点与其他所有点的胜负关系即可，用 vis标记

 注意如果从 1-n的话哈希要 *(n+1)，并且空间上 maxn=1001*2*1001*2=4008004，大概需要开 5e6的空间
 并且 re在慢的评测机上会 tle

 这个代码不开 long long并且循环展开，跑 234ms
 
 下面代码的思路更简洁，并且开 long long不开循环展开跑 61ms
*/
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=5e6+3;
constexpr int M=1e3+3;
int dx[7]={1,0,-1,0};
int dy[7]={0,1,0,-1};
int n,m;
char mp[M][M];
int vis[N];
bool flag[N];
int gao(int i,int j,int r,int c)
{
    return 
        i*(n+1)*(m+1)*(m+1)+
        j*(n+1)*(m+1)+
        r*(m+1)+
        c;
}
void ungao(int msk,int &i,int &j,int &r,int &c)
{
    i=msk/((n+1)*(m+1)*(m+1));
    j=(msk/((n+1)*(m+1)))%(m+1);
    r=(msk/(m+1))%(n+1);
    c=msk%(m+1);
}
bool fall(int x,int y)
{
    return x<1||x>n||y<1||y>m||mp[x][y]!='.';
}
void bfs(int idx)
{
    flag[idx]=0;
    queue<int> q;
    q.push(idx);
    vis[idx]=idx;

    while(!q.empty())
    {
        int i,j,r,c;
        ungao(q.front(),i,j,r,c);
        q.pop();

        for(int k=0;k<4;k++)
        {
            int ii=i+dx[k],jj=j+dy[k];
            int rr=r+dx[k],cc=c+dy[k];

            if(fall(ii,jj)) continue;

            if(fall(rr,cc))
            {
                flag[idx]=1;
                continue;
            }
            int nxt=gao(ii,jj,rr,cc);
            if(vis[nxt]>=0) continue;
            q.push(nxt);
            vis[nxt]=idx;
        }
    }
}
int check(int i,int j)
{
    for(int r=1;r<=n;r++)
    {
        for(int c=1;c<=m;c++)
        {
            if(mp[r][c]!='.') continue;
            if(i==r&&j==c) continue;
            int msk=gao(i,j,r,c);
            if(vis[msk]==-1) bfs(msk);
            if(!flag[vis[msk]]) return 0;
        }
    }
    return 1;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }

    memset(vis,-1,sizeof(int)*((n+1)*(m+1)*(n+1)*(m+1)+2));

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='.') ans+=check(i,j);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int dx[7]={0,1,0,-1};
int dy[7]={1,0,-1,0};
int n,m;
char mp[M][M];
int vis[M][M];
bool fall(int x,int y)
{
    return x<0||x>=n||y<0||y>=m||mp[x][y]!='.';
}
int bfs(int idx,int i,int j)
{
    queue<pair<int,int> > q;
    q.push({0,0});
    vis[i][j]=idx;
    vector<pair<int,int> > path; // 记录从 i,j走到该连通块其他点的偏移量，因为 i,j只能走这些位置，并且连通块的赢输是共享的
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        path.push_back({x,y});
        x+=i,y+=j;

        for(int k=0;k<4;k++)
        {
            int xx=x+dx[k],yy=y+dy[k];
            if(fall(xx,yy)) continue;
            if(vis[xx][yy]) continue;
            vis[xx][yy]=idx; // 这个循环不打标记的话，会有相同的点被 push进队列
            q.push({xx-i,yy-j});
        }
    }

    bool ok=1;
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<m;c++)
        {
            if(vis[r][c]==idx||mp[r][c]!='.') continue;
            bool flag=0;
            for(auto [tx,ty]:path)
            {
                int rr=r+tx,cc=c+ty;
                if(fall(rr,cc))
                {
                    flag=1;
                    break;
                }
            }
            if(!flag) ok=0;
        }
        if(!ok) break;
    }
    if(ok) return path.size();
    return 0;
}
void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mp[i][j];
            vis[i][j]=0;
        }
    }

    int idx=0,ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]!='.'||vis[i][j]) continue;
            ans+=bfs(++idx,i,j);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/