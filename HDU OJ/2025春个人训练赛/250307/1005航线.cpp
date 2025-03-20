/*
 * @Author: dsaDadas11
 * @Date: 2025-03-08 19:20:40
 * @LastEditTime: 2025-03-08 19:32:40
 * @Description: go for it!
 */
/*
 解题思路：
 1.加了方向的 dijkstra,感觉很玄学
 2.优先队列中结构体重载的方向与平常的相反
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int inf=1e16;
using PII=pair<int,int>;
int dx[7]={0,1,0,-1};
int dy[7]={1,0,-1,0};
int n,m;
int t[N],d[N];
int dist[N][4];
bool vis[N][4];
int calc(int x,int y)
{
    return (x-1)*m+y;
}
PII calp(int p)
{
    p--;
    return {p/m+1,p%m+1};
}
struct op
{
    int val,p,dir;
    bool operator<(const op&a) const
    {
        return val>a.val;
    }
};
bool check(int x,int y)
{
    return !(x<1||x>n||y<1||y>m);
}
void dijkstra()
{
    int st=1,ed=n*m;
    for(int i=1;i<=n*m;i++)
    {
        for(int j=0;j<4;j++)
        {
            dist[i][j]=inf;
            vis[i][j]=0;
        }
    }
    priority_queue<op> pq;
    // 0右 1下 2左 3上
    dist[st][0]=t[st];
    pq.push({0,st,0});
    while(!pq.empty())
    {
        auto [val,p,dir]=pq.top();
        pq.pop();
        if(vis[p][dir]) continue;
        vis[p][dir]=1;
        for(int i=0;i<4;i++)
        {
            if(dist[p][dir]+d[p]<dist[p][i])
            {
                dist[p][i]=dist[p][dir]+d[p];
                pq.push({dist[p][i],p,i});
            }
        }
        auto [x,y]=calp(p);
        int xx=x+dx[dir],yy=y+dy[dir];
        int pp=calc(xx,yy);
        if(check(xx,yy)&&dist[p][dir]+t[pp]<dist[pp][dir])
        {
            dist[pp][dir]=dist[p][dir]+t[pp];
            pq.push({dist[pp][dir],pp,dir});
        }
    }
    cout<<dist[ed][1]<<endl;
}
void solve()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>t[calc(i,j)];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>d[calc(i,j)];
        }
    }
    dijkstra();
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}