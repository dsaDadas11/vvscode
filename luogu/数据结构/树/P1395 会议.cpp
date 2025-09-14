/*
 * @Author: dsaDadas11
 * @Date: 2025-07-21 15:42:32
 * @LastEditTime: 2025-07-21 15:42:49
 * @Description: go for it!
 */
/*
 树的重心例题
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
vector<int> g[N];
int anss=1e9,ansu;
int dfs(int u,int fax)
{
    int sz=0; // u的最大子树大小
    int sum=1; // 以 u为根的子树的节点数
    for(auto v:g[u])
    {
        if(v==fax) continue;
        int s=dfs(v,u);
        sz=max(sz,s);
        sum+=s;
    }
    int res=max(sz,n-sum);
    if(anss==res)
    {
        if(!ansu) ansu=u;
        else ansu=min(ansu,u);
    }
    else if(anss>res) anss=res,ansu=u;
    return sum;
}
int dist[N];
int res;
void bfs()
{
    queue<int> q;
    q.push(ansu);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            if(dist[v]||v==ansu) continue;
            dist[v]=dist[u]+1;
            res+=dist[v];
            q.push(v);
        }
    }
}
void solve()
{
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    bfs();
    cout<<ansu<<' '<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}