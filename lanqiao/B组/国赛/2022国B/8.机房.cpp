/*
 * @Author: dsaDadas11
 * @Date: 2025-06-13 11:57:12
 * @LastEditTime: 2025-06-13 11:57:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
vector<int> g[N];
int dep[N],fa[N][20];
int du[N],sum[N];
void dfs(int u,int fax)
{
    dep[u]=dep[fax]+1;
    fa[u][0]=fax;
    sum[u]+=sum[fax];
    for(int j=1;j<20;j++)
    {
        fa[u][j]=fa[fa[u][j-1]][j-1];
    }
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
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
void solve()
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        du[u]++,du[v]++;
        sum[u]++,sum[v]++;
    }
    dfs(1,0);

    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        if(u==v)
        {
            cout<<du[u]<<endl;
            continue;
        }
        int lc=lca(u,v);
        cout<<sum[u]-sum[lc]+sum[v]-sum[lc]+du[lc]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}