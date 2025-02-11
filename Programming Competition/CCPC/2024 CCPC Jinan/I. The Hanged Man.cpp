/*
 * @Author: dsaDadas11
 * @Date: 2025-01-15 19:06:07
 * @LastEditTime: 2025-01-15 19:06:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int d[N];
vector<int> g[N];
vector<pair<int,int> > ans;
int dfs(int u,int fax)
{
    int last=0;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        int w=dfs(v,u);
        if(last) ans.push_back({last,w}),last=0;
        else last=w;
    }
    if(!last) return u;
    return last;
}
void solve()
{
    cin>>n;
    for(int i=0;i<=n+5;i++)
    {
        g[i].clear();
        d[i]=0;
    }
    ans.clear();
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++,d[v]++;
    }
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]%2==0)
        {
            flag=1;
            dfs(i,0);
            break;
        }
    }
    if(!flag) return cout<<"-1"<<endl,void();
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans)
    {
        cout<<x<<' '<<y<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}