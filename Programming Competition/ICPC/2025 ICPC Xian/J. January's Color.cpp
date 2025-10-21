/*
 * @Author: dsaDadas11
 * @Date: 2025-10-20 16:44:36
 * @LastEditTime: 2025-10-20 16:45:06
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e5+7;
constexpr int M=2e3+7;
int n,m;
int c[N],fa[N][20],dep[N];
int f[N];
vector<int> g[N];
int sum[N];
void init()
{
    for(int i=1;i<=n;i++)
    {
        dep[i]=f[i]=sum[i]=0;
        g[i].clear();
    }
}
void dfs2(int u,int fax)
{
    dep[u]=dep[fax]+1;
    fa[u][0]=fax;
    for(int j=1;j<20;j++)
    {
        fa[u][j]=fa[fa[u][j-1]][j-1];
    }
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs2(v,u);
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

void dfs(int u,int fax)
{
    for(int v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
    }

    vector<pair<int,int> > adj;
    for(int v:g[u])
    {
        if(v==fax) continue;
        adj.push_back({c[v],v});
    }
    sort(adj.begin(),adj.end());
    for(int v:g[u])
    {
        if(v==fax) continue;
        int res=0;
        if(adj[0].second==v) res=adj[1].first;
        else res=adj[0].first;
        f[v]=res;
    }

    for(int v:g[u])
    {
        if(v==fax) continue;
        c[u]=min(c[u],f[v]+c[v]);
    }
}
void dfs3(int u,int fax)
{
    sum[u]=sum[fax]+f[u];
    for(int v:g[u])
    {
        if(v==fax) continue;
        dfs3(v,u);
    }
}
void solve()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++) cin>>c[i];
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs2(1,0);
    dfs(1,0);
    dfs3(1,0);

    while(m--)
    {
        cin>>u>>v;
        if(u==v)
        {
            cout<<0<<endl;
            continue;
        }
        if(dep[u]<=dep[v])
        {
            cout<<-1<<endl;
            continue;
        }
        if(lca(u,v)!=v)
        {
            cout<<-1<<endl;
            continue;
        }

        cout<<sum[u]-sum[v]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}