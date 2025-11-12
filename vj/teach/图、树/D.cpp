/*
 * @Author: dsaDadas11
 * @Date: 2025-10-27 20:13:48
 * @LastEditTime: 2025-10-27 20:13:57
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e3+7;
constexpr int mod=80112002;
int n,m;
vector<int> g[N];
int ind[N];
int outd[N];
int f[N];
void solve()
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[v].push_back(u);
        ind[u]++;
        outd[v]++;
    }

    vector<int> s;
    for(int i=1;i<=n;i++)
    {
        if(outd[i]==0) s.push_back(i);
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            f[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            f[v]=(f[v]+f[u])%mod;
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }

    int ans=0;
    for(auto i:s)
    {
        ans=(ans+f[i])%mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}