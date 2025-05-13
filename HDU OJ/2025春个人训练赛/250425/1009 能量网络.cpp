/*
 * @Author: dsaDadas11
 * @Date: 2025-04-27 15:12:43
 * @LastEditTime: 2025-04-27 15:16:24
 * @Description: go for it!
 */
/*
 解题思路：
 若 A,B两者有能量光束，则把 AB看成一个点，坐标变为 ( x1+x2, y1+y2, z1+z2)
 然后根据 x, y, z排序，每次选择相邻的 x, y, z使得边权值 cost最小 (将 i和 i+1连边, cost为权值)
 最后根据 cost排序，用并查集判断两个点是否在同一集合
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int x[N],y[N],z[N];
struct Edge
{
    int x,y,z;
    int i;
};
bool cmp_x(Edge e1,Edge e2)
{
    return e1.x<e2.x;
}
bool cmp_y(Edge e1,Edge e2)
{
    return e1.y<e2.y;
}
bool cmp_z(Edge e1,Edge e2)
{
    return e1.z<e2.z;
}
int fa[N];
int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
void merge_set(int x,int y)
{
    int fax=find_fa(x);
    int fay=find_fa(y);
    fa[fax]=fay;
}
int calc(Edge e1,Edge e2)
{
    return min({abs(e1.x-e2.x),abs(e1.y-e2.y),abs(e1.z-e2.z)});
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) fa[i]=i;

    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }

    int u,v;
    vector<Edge> g;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g.push_back({x[u]+x[v],y[u]+y[v],z[u]+z[v],i});
    }

    vector<tuple<int,int,int> > vt; // cost  u  v
    sort(g.begin(),g.end(),cmp_x);
    for(int i=0;i<m-1;i++)
    {
        u=g[i].i,v=g[i+1].i;
        vt.push_back({calc(g[i],g[i+1]),u,v});
    }

    sort(g.begin(),g.end(),cmp_y);
    for(int i=0;i<m-1;i++)
    {
        u=g[i].i,v=g[i+1].i;
        vt.push_back({calc(g[i],g[i+1]),u,v});
    }

    sort(g.begin(),g.end(),cmp_z);
    for(int i=0;i<m-1;i++)
    {
        u=g[i].i,v=g[i+1].i;
        vt.push_back({calc(g[i],g[i+1]),u,v});
    }

    int ans=0;
    sort(vt.begin(),vt.end());
    for(auto [cost,u,v]:vt)
    {
        int fax=find_fa(u);
        int fay=find_fa(v);
        if(fax==fay) continue;
        ans+=cost;
        merge_set(u,v);
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