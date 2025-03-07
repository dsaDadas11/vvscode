/*
 * @Author: dsaDadas11
 * @Date: 2025-03-05 20:01:24
 * @LastEditTime: 2025-03-05 20:18:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e16;
int n,m;
int dist[107][107];
int d[107][107];
int ans=inf;
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
        {
            for(int j=1;j<k;j++)
            {
                if(i==j) continue;
                ans=min(ans,dist[i][j]+d[i][k]+d[k][j]);
            }
        }
        for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    }

}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) dist[i][j]=d[i][j]=0;
            else dist[i][j]=d[i][j]=inf;
        }
    }
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }
    floyd();
    if(ans==inf) cout<<"No solution."<<endl;
    else cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}