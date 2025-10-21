/*
 * @Author: dsaDadas11
 * @Date: 2025-10-18 19:03:00
 * @LastEditTime: 2025-10-18 19:03:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int a[N],c[N];
vector<int> g[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    vector<int> d(n+2,0),ans(n+3,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        g[i].push_back(a[i]);
        d[a[i]]++;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }

    queue<int> q;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0) q.push(i);
    }
    int cnt=0;
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans[++cnt]=u;
        vis[u]=1;
        for(int v:g[u])
        {
            d[v]--;
            if(d[v]==0) q.push(v);
        }
    }

    vector<int> loop;
    for(int i=1;i<=n;i++)
    {
        if(d[i]>0) loop.push_back(i);
    }

    sort(loop.begin(),loop.end(),[&](auto &a,auto &b) {
        return c[a]<c[b];
    });


    function<void(int)> dfs=[&](int u) {
        if(vis[u]) return;
        vis[u]=1;
        ans[++cnt]=u;
        for(int v:g[u])
        {
            if(vis[v]) continue;
            dfs(v);
        }
    };
    

    for(int u:loop)
    {
        if(vis[u]) continue;
        vis[u]=1;
        dfs(g[u][0]);
        ans[++cnt]=u;
    }
    
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}