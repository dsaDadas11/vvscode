/*
 * @Author: dsaDadas11
 * @Date: 2025-11-12 21:47:04
 * @LastEditTime: 2025-11-12 21:47:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int dep[N],fa[N][20];
vector<int> g[N];
void dfs(int u,int fax)
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
int n,q,m;
void solve()
{
    cin>>n;
    int x,y;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        x++;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1,0);
    cin>>q;
    while(q--)
    {
        cin>>m;
        cin>>x>>y;
        x++,y++;
        int ans=lca(x,y);
        for(int i=3;i<=m;i++)
        {
            cin>>x;
            x++;
            ans=lca(ans,x);
        }
        int t=ans;
        while(ans!=0)
        {
            ans=fa[ans][0];
            t=max(t,ans);
        }
        cout<<t-1<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}