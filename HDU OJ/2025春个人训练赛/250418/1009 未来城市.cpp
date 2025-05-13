/*
 * @Author: dsaDadas11
 * @Date: 2025-04-20 16:21:55
 * @LastEditTime: 2025-04-20 16:26:33
 * @Description: go for it!
 */
/*
 解题思路：
 先将数组按 w从大到小排序，
 当集合中边的数量小于点的数量时，需要将遍历的这条边加入集合，或者将 u,v合并后加入这条边
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
struct op
{
    int a,b,w;
    bool operator<(const op&that) const
    {
        return w>that.w;
    }
}p[N];
int edge[N],node[N],fa[N];
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
    edge[fay]+=edge[fax];
    node[fay]+=node[fax];
}
void init()
{
    for(int i=1;i<=n;i++) fa[i]=i,node[i]=1,edge[i]=0;
}
void solve()
{
    cin>>n>>m;
    init();
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        p[i]={u,v,w};
    }
    sort(p+1,p+1+m);
    
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        auto [u,v,w]=p[i];
        int fau=find_fa(u);
        int fav=find_fa(v);
        if(fau==fav)
        {
            if(edge[fau]<node[fau])
            {
                ans+=w;
                edge[fau]++;
            }
        }
        else
        {
            if(edge[fau]<node[fau]||edge[fav]<node[fav])
            {
                ans+=w;
                merge_set(u,v);
                edge[find_fa(u)]++; // 还有遍历的这条边需要加进去
            }
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