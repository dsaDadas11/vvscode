/*
 * @Author: dsaDadas11
 * @Date: 2025-08-18 20:29:02
 * @LastEditTime: 2025-08-18 20:30:01
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
vector<pair<int,int> > g[N];
int ind[N],k[N];
double f[N]; // i到 n的期望
void bfs()
{
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto [v,w]:g[u])
        {
            f[v]+=1.0*(f[u]+w)/k[v]; // 不能用g[u]或者g[v]的大小，因为这要算 v的出边，而我们建的是反图，所以不能g[]大小
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
}
void solve()
{
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[v].push_back({u,w});
        ind[u]++,k[u]++;
    }
    bfs();
    cout<<fixed<<setprecision(2)<<f[1]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}