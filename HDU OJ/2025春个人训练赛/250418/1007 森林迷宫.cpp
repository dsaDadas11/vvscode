/*
 * @Author: dsaDadas11
 * @Date: 2025-04-18 19:47:43
 * @LastEditTime: 2025-04-22 21:15:57
 * @Description: go for it!
 */
/*
 解题思路：
 树形 dp + lca求 u,v路径，思维简单但是代码难写
 可以先 dfs求出 dp,然后再一个 dfs求出路径，值得学习
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,s,t;
vector<pair<int,int> > g[N];
int dp[N];
map<pair<int,int>,int> mp;
bool vis[N];
void dfs2(int u,int fax)
{
    for(auto [v,w]:g[u])
    {
        if(v==fax) continue;
        dfs2(v,u);
        if(vis[v]) continue;
        int res=dp[v]+mp[{u,v}]+mp[{v,u}];
        if(res>0) dp[u]+=res;
    }
}
int dep[N],fa[N][20];
void dfs1(int u,int fax)
{
    dep[u]=dep[fax]+1;
    fa[u][0]=fax;
    for(int j=1;j<20;j++)
    {
        fa[u][j]=fa[fa[u][j-1]][j-1];
    }
    for(auto [v,w]:g[u])
    {
        if(v==fax) continue;
        dfs1(v,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int j=19;j>=0;j--)
    {
        if(dep[fa[x][j]]>=dep[y]) x=fa[x][j];
        if(x==y) return x;
    }
    for(int j=19;j>=0;j--)
    {
        if(fa[x][j]!=fa[y][j])
        {
            x=fa[x][j];
            y=fa[y][j];
        }
    }
    return fa[x][0];
}
int ans;
vector<int> d;
void dfs3(int u,int fax)
{
    d.push_back(u);
    vis[u]=1;
    for(auto [v,w]:g[u])
    {
        if(v==fax) continue;
        if(lca(t,v)!=v) continue;
        ans+=w;
        dfs3(v,u);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear(),dep[i]=0,dp[i]=0,vis[i]=0;
    d.clear();
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<20;j++)
        {
            fa[i][j]=0;
        }
    }
    ans=0;
    int u,v,p,q;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>p>>q;
        g[u].push_back({v,p});
        g[v].push_back({u,q});
        mp[{u,v}]=p;
        mp[{v,u}]=q;
    }
    cin>>s>>t;
    dfs1(s,0);
    dfs3(s,0);
    dfs2(s,0);
    for(auto u:d)
    {
        ans+=dp[u];
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
constexpr int M=2e3+7;
int n,s,t;
vector<tuple<int,int,int> > g[N];
int dp[N];
void dfs(int u,int fax)
{
    for(auto [v,p,q]:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
        dp[u]+=max(0LL,dp[v]+p+q);
    }
}
pair<bool,int> find_dist(int u,int fax)
{
    if(u==t) return {1,dp[u]};
    int res=0;
    bool ok=0;
    for(auto [v,p,q]:g[u])
    {
        if(v==fax) continue;
        auto [flag,val]=find_dist(v,u);
        if(flag) ok=1,res+=val+p;
        else res+=max(0LL,dp[v]+p+q);
    }
    return {ok,res};
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        dp[i]=0;
    }
    int u,v,p,q;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>p>>q;
        g[u].push_back({v,p,q});
        g[v].push_back({u,q,p});
    }
    
    cin>>s>>t;
    dfs(s,0);
    auto [ok,ans]=find_dist(s,0);
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