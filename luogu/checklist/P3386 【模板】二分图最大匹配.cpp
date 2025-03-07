/*
 * @Author: HuangCe
 * @Date: 2025-02-25 19:16:08
 * @LastEditTime: 2025-02-25 19:22:17
 * @Description: go for it!
 */
/*
 二分图匹配是指两个集合之间相连的边中没有相同的顶点的数量
 简单来说 左边是男，右边是女，能匹配到的最大情侣数量就是二分图最大匹配
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e4+7;
constexpr int M=2e3+7;
int n,m,e;
int vis[507];
int match[507]; // 女匹配男 vis[女]=男
vector<int> g[N];
bool dfs(int u)
{
    for(auto v:g[u])
    {
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v]||dfs(match[v]))
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
void solve()
{
    cin>>n>>m>>e;
    int u,v;
    for(int i=1;i<=e;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=m;i++) vis[i]=0;
        if(dfs(i)) ans++;
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