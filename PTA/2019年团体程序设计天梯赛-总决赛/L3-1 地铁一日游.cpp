/*
 * @Author: dsaDadas11
 * @Date: 2025-04-17 15:23:31
 * @LastEditTime: 2025-04-17 15:26:05
 * @Description: go for it!
 */
/*
 解题思路：
 题目要求找 1.相同费用的最远距离 2.端点
 可以用 floyd求出多源最短路，然后遍历每个点寻找符合要求的点
 要注意的是：
 使用 getchar()不能关闭流同步
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
constexpr int inf=1e16;
int n,m,k,q,x;
vector<int> g[N];
int dist[N][N];
bool vis[N],edp[N];
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        map<int,int> mp;
        for(int j=1;j<=n;j++)
        {
            if(i==j||dist[i][j]==inf) continue;
            mp[2+dist[i][j]/k]=max(mp[2+dist[i][j]/k],dist[i][j]);
        }

        for(int j=1;j<=n;j++)
        {
            if(i==j||dist[i][j]==inf) continue;
            if(mp[2+dist[i][j]/k]==dist[i][j]||edp[j]) g[i].push_back(j);
        }
    }
}
void dfs(int u)
{
    vis[u]=1;
    for(auto v:g[u])
    {
        if(vis[v]) continue;
        dfs(v);
    }
}
void solve()
{
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            dist[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u;
        edp[u]=1;
        while(getchar()==' ')
        {
            cin>>w>>v;
            dist[u][v]=dist[v][u]=min(dist[u][v],w);
            u=v;
        }
        edp[v]=1;
    }

    floyd();

    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>x;
        for(int j=1;j<=n;j++) vis[j]=0;
        dfs(x);
        vector<int> ans;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]) ans.push_back(j);
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        for(int j=0;j<ans.size();j++)
        {
            if(j) cout<<' ';
            cout<<ans[j];
        }
        cout<<endl;
    }
}
signed main()
{
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}