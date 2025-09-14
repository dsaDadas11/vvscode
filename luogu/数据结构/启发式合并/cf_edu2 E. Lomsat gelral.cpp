/*
 * @Author: dsaDadas11
 * @Date: 2025-09-03 22:16:12
 * @LastEditTime: 2025-09-03 22:16:44
 * @Description: go for it!
 */
// URL:https://codeforces.com/problemset/problem/600/E
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int c[N],cnt[N];
int son[N],sz[N];
int mx,sum;
int ans[N];
vector<int> g[N];
void dfs1(int u,int fax)
{
    sz[u]=1;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void add(int u,int fax,int s) // u的重儿子
{
    cnt[c[u]]++;
    if(cnt[c[u]]>mx) mx=cnt[c[u]],sum=c[u];
    else if(cnt[c[u]]==mx) sum+=c[u];

    for(auto v:g[u])
    {
        if(v==fax||v==s) continue;
        add(v,u,s);
    }
}
void sub(int u,int fax)
{
    cnt[c[u]]--;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        sub(v,u);
    }
}
void dfs2(int u,int fax,bool lig) // 是否为轻子树
{
    for(auto v:g[u]) // 先搜轻子树
    {
        if(v==fax||v==son[u]) continue;
        dfs2(v,u,1);
    }
    if(son[u]) dfs2(son[u],u,0); // 后搜重子树,为 0不会清除 sum和 mx

    add(u,fax,son[u]); // 加上轻子树
    ans[u]=sum;
    if(lig) // 减掉轻子树的贡献
    {
        sub(u,fax);
        mx=sum=0;
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1,0);
    dfs2(1,0,0);

    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}