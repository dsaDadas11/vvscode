/*
 * @Author: dsaDadas11
 * @Date: 2025-09-08 19:20:33
 * @LastEditTime: 2025-09-08 19:20:43
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e9;
int n;
int a[N];
vector<int> g[N];
array<int,3> dfs(int u,int fax)
{
    if(g[u].size()==1&&u!=1)
    {
        return {0,a[u],-a[u]};
    }
    
    vector<int> ups{0},downs{0};
    int sum=0;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        auto [val,up,down]=dfs(v,u);
        sum+=val;
        ups.push_back(up-val);
        downs.push_back(down-val);
    }

    int m=ups.size()-1;
    vector<int> preup=ups,sufup=ups;
    vector<int> predown=downs,sufdown=downs;
    for(int i=2;i<=m;i++)
    {
        preup[i]=max(preup[i-1],ups[i]);
        predown[i]=max(predown[i-1],downs[i]);
    }
    for(int i=m-1;i>=1;i--)
    {
        sufup[i]=max(sufup[i+1],ups[i]);
        sufdown[i]=max(sufdown[i+1],downs[i]);
    }

    // u只连一个子树 (不是最值、最小值、最大值)
    int val=max({sum,sum+preup[m]-a[u],sum+predown[m]+a[u]});
    
    // 连两个子树
    for(int i=1;i<m;i++)
    {
        val=max(val,sum+preup[i]+sufdown[i+1]);
        val=max(val,sum+predown[i]+sufup[i+1]);
    }

    int up=max(sum+a[u],sum+preup[m]);
    int down=max(sum-a[u],sum+predown[m]);
    
    return {val,up,down};
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    cout<<dfs(1,0)[0]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}