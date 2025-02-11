/*
 * @Author: dsaDadas11
 * @Date: 2025-01-16 20:51:26
 * @LastEditTime: 2025-01-16 20:52:30
 * @Description: go for it!
 */
/*
 解题思路：
 二分图染色
 当把深度为奇染色和深度为偶染色 集合是最大的
 因为集合间最大的边长是 x*y
 那么 ans = x*y - (n-1)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int dep[N];
vector<int> g[N];
void dfs(int u,int fa,int stp)
{
    dep[u]=stp;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u,stp+1);
    }
}
void solve()
{
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,1);
    int x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        if(dep[i]&1) x++;
        else y++;
    }
    cout<<x*y-(n-1)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}