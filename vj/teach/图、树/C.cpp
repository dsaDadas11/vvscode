/*
 * @Author: dsaDadas11
 * @Date: 2025-10-27 16:35:51
 * @LastEditTime: 2025-10-27 16:35:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
int n;
vector<int> g[N];
int w[N];
int ind[N];
int f[N];
void solve()
{
    cin>>n;
    int idx,len,u;
    for(int i=1;i<=n;i++)
    {
        cin>>idx>>len;
        w[idx]=len;
        while(cin>>u&&u)
        {
            g[u].push_back(idx);
            ind[idx]++;
        }
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        f[u]+=w[u];
        for(auto v:g[u])
        {
            ind[v]--;
            f[v]=max(f[v],f[u]);
            if(ind[v]==0) q.push(v);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[i]);
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