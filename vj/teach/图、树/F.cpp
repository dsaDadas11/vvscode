/*
 * @Author: dsaDadas11
 * @Date: 2025-10-28 14:55:30
 * @LastEditTime: 2025-10-28 14:55:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int k,n,m;
int c[107];
vector<int> g[N];
int ans[N],cnt[N];
bool vis[N];
void dfs(int u,int res)
{
    if(vis[u]) return;
    vis[u]=1;
    ans[u]+=res;

    for(auto v:g[u])
    {
        if(vis[v]) continue;
        dfs(v,res);
    }
}
void solve()
{
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        cnt[c[i]]++;
    }

    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) vis[j]=0;
        dfs(i,cnt[i]);
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==k) cnt++;
    }
    cout<<cnt<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}