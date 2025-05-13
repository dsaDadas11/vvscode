/*
 * @Author: dsaDadas11
 * @Date: 2025-05-09 20:19:45
 * @LastEditTime: 2025-05-09 20:19:54
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
bool check(int x,int fa)
{
    if(x==0) return 1;
    for(auto v:g[x])
    {
        if(v==fa) continue;
        if(v>x) continue;
        return 1;
    }
    return 0;
}
bool dfs(int u)
{
    // 切绳子
    for(auto v:g[u])
    {
        if(v>u) continue; // 已经被切过
        if(!check(v,u)) return 0;
    }
    return 1;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) g[i].clear();
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=n;i>=1;i--)
    {
        if(!dfs(i))
        {
            cout<<"0"<<endl;
            return;
        }
    }
    cout<<"1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}