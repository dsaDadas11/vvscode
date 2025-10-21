/*
 * @Author: dsaDadas11
 * @Date: 2025-09-29 20:01:38
 * @LastEditTime: 2025-09-29 20:01:45
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q;
int f[107][107];
vector<pair<int,int> > g[107];
void dfs(int u,int fax)
{
    for(auto [v,w]:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
        for(int j=q;j>=1;j--)
        {
            for(int k=0;k<=j-1;k++)
            {
                f[u][j]=max(f[u][j],f[u][j-k-1]+f[v][k]+w); // 得加一条边[u,v]
            }
        }
    }
}
void solve()
{
    cin>>n>>q;
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    cout<<f[1][q]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}