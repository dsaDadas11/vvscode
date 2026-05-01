/*
 * @Author: dsaDadas11
 * @Date: 2026-01-29 17:50:35
 * @LastEditTime: 2026-01-29 17:50:42
 * @Description: go for it!
 */
// 差点忘记最小生成树怎么写了555
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
double x[107],y[107];
double calc(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
vector<pair<double,int> > g[107];
bool vis[107];
double dist[107];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            g[i].push_back({sqrt(calc(i,j)),j});
        }
    }

    double ans=0.0;
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<> > pq;
    // priority_queue<int,vector<int>,greater<> > pq;

    for(auto [d,t]:g[1]) pq.push({d,t});
    vis[1]=1;
    while(!pq.empty())
    {
        double dmin=pq.top().first;
        int s=pq.top().second;
        pq.pop();
        if(vis[s]) continue;
        vis[s]=1;
        for(auto [d,t]:g[s])
        {
            // if(vis[t]) continue;
            pq.push({d,t});
        }
        ans+=dmin;
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