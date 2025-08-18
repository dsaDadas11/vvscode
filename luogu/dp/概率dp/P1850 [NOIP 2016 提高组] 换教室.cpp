/*
 * @Author: dsaDadas11
 * @Date: 2025-08-18 20:08:06
 * @LastEditTime: 2025-08-18 20:08:16
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,v,e;
int c[M],d[M];
double p[M];
int dist[307][307];
double f[M][M][2];
void solve()
{
    cin>>n>>m>>v>>e;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=v;i++) dist[i][i]=0;
    int a,b,w;
    for(int i=1;i<=e;i++)
    {
        cin>>a>>b>>w;
        dist[a][b]=dist[b][a]=min(dist[a][b],w);
    }

    for(int k=1;k<=v;k++)
    {
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j][0]=f[i][j][1]=1e16;
        }
    }
    f[1][0][0]=f[1][1][1]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=min(i,m);j++)
        {
            // 这次没选，上次选了/没选
            f[i][j][0]=min(f[i-1][j][1]+dist[d[i-1]][c[i]]*p[i-1]+dist[c[i-1]][c[i]]*(1-p[i-1]),f[i-1][j][0]+dist[c[i-1]][c[i]]);

            // 这次选了，上次选了/没选
            if(j>=1)
            {
                f[i][j][1]=min(f[i-1][j-1][1]+dist[c[i-1]][c[i]]*(1-p[i-1])*(1-p[i])+dist[d[i-1]][c[i]]*p[i-1]*(1-p[i])+
                                                dist[d[i-1]][d[i]]*p[i-1]*p[i]+dist[c[i-1]][d[i]]*(1-p[i-1])*p[i],
                            f[i-1][j-1][0]+dist[c[i-1]][c[i]]*(1-p[i])+dist[c[i-1]][d[i]]*p[i]);
            }
        }
    }
    double ans=1e16;
    for(int j=0;j<=m;j++)
    {
        ans=min({ans,f[n][j][0],f[n][j][1]});
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}