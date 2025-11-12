/*
 * @Author: dsaDadas11
 * @Date: 2025-10-23 20:30:29
 * @LastEditTime: 2025-10-23 20:30:36
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int c[N];
vector<int> g[N];
void solve()
{
    cin>>n;
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        g[i].clear();
    }

    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans=0;

    auto dfs = [&](auto self,int u,int fax) -> void {
        int res=cnt[c[u]];
        for(auto v:g[u])
        {
            if(v==fax) continue;
            cnt[c[u]]=1;
            self(self,v,u);
        }
        ans+=res;
        cnt[c[u]]=res+1;
    };

    dfs(dfs,1,0);
    
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}