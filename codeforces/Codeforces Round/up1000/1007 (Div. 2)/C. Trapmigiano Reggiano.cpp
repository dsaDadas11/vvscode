/*
 * @Author: dsaDadas11
 * @Date: 2025-03-26 20:41:33
 * @LastEditTime: 2025-03-26 20:43:34
 * @Description: go for it!
 */
/*
 解题思路：
 将 ed为根然后求出深度，再按深度从大到小遍历，一定能回到根节点
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,st,ed;
vector<int> g[N];
int dep[N];
void dfs(int u,int fax)
{
    dep[u]=dep[fax]+1;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
    }
}
void solve()
{
    cin>>n>>st>>ed;
    for(int i=0;i<=n+3;i++)
    {
        g[i].clear();
        dep[i]=0;
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(ed,0);
    vector<pair<int,int> > p;
    for(int i=1;i<=n;i++)
    {
        p.push_back({dep[i],i});
    }
    sort(p.begin(),p.end(),greater<>());
    
    for(auto [x,y]:p)
    {
        cout<<y<<' ';
    }
    cout<<endl;
    
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}