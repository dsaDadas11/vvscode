/*
 * @Author: dsaDadas11
 * @Date: 2025-04-05 10:31:02
 * @LastEditTime: 2025-04-05 11:50:59
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
vector<int> g[N];
int col[N];
int sum[3];
bool dfs(int u,int c) // 0: 是二分图  1: 不是二分图
{
    col[u]=c;
    sum[col[u]]++; // 每次 dfs统计 1,2两种颜色的数量
    for(auto v:g[u])
    {
        if(!col[v]) // 如果没被染色
        {
            if(dfs(v,3-c)) return 1; // 将 v染色后递归下一个点
        }
        else if(col[v]==c) return 1; // 如果颜色相同则矛盾，不是二分图
    }
    return 0;
}
void solve()
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(col[i]) continue;
        sum[1]=sum[2]=0; // 注意清空
        if(dfs(i,2)) return cout<<"Impossible"<<endl,void();
        ans+=min(sum[1],sum[2]); // 取二分图左右顶点数最小的
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