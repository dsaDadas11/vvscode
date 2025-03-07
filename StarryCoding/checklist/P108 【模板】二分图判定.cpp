/*
 * @Author: HuangCe
 * @Date: 2025-02-25 19:07:25
 * @LastEditTime: 2025-02-25 19:22:37
 * @Description: go for it!
 */
/*
 二分图染色就是将二分图的两个集合染成1和2两种颜色
 因为集合内的点是不能有边相连的，因此存在边就一定为相反集合，
 然后枚举每条边染色，看是否会出现矛盾
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
int color[N];
bool dfs(int u,int c) // 不能形成二分图 0
{
    color[u]=c;
    for(auto v:g[u])
    {
        if(!color[v])
        {
            if(!dfs(v,3-c))
            {
                return 0;
            }
        }
        else if(color[v]==c) return 0;
    }
    return 1;
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
    for(int i=1;i<=n;i++)
    {
        if(color[i]) continue;
        if(!dfs(i,2)) return cout<<"NO"<<endl,void();
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}