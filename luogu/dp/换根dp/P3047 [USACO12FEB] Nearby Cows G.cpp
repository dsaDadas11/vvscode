/*
 * @Author: dsaDadas11
 * @Date: 2025-08-14 20:01:23
 * @LastEditTime: 2025-08-14 20:01:35
 * @Description: go for it!
 */
/*
 处理距离 i节点 k个距离的点的思路非常好
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,k;
vector<int> g[N];
int c[N];
int f[N][27],d[N][27];
// 从 i往下 j，从 i往上和往下 j
void dfs1(int u,int fax)
{
    for(int j=0;j<=k;j++) f[u][j]=c[u];
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs1(v,u);
        for(int j=1;j<=k;j++)
        {
            f[u][j]+=f[v][j-1];
        }
    }
}
void dfs2(int u,int fax)
{
    for(auto v:g[u])
    {
        if(v==fax) continue;
        for(int j=1;j<=k;j++)
        {
            if(j==1) d[v][j]+=c[u];
            else d[v][j]+=d[u][j-1]-f[v][j-2];
        }
        dfs2(v,u);
    }
}
void solve()
{
    cin>>n>>k;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs1(1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            d[i][j]=f[i][j];
        }
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout<<d[i][k]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}