/*
 * @Author: dsaDadas11
 * @Date: 2025-04-05 11:22:31
 * @LastEditTime: 2025-04-05 11:47:18
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
vector<int> g[M<<1];
// 一个座位可以坐两个人，就按 0 1将一个座位划分为两个不同的座位
int match[M][2];
bool vis[M][2];
vector<pair<int,int> > tmp; // vis清空数组
bool dfs(int u)
{
    for(auto v:g[u])
    {
        for(int i=0;i<2;i++)
        {
            if(vis[v][i]) continue;
            vis[v][i]=1;
            tmp.push_back({v,i}); // 记录哪些点需要清空
            if(!match[v][i]||dfs(match[v][i]))
            {
                match[v][i]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    cin>>n;
    int v1,v2;
    for(int i=1;i<=n*2;i++)
    {
        cin>>v1>>v2;
        g[i].push_back(v1);
        g[i].push_back(v2);
    }
    
    int ans=0;
    for(int i=1;i<=n*2;i++)
    {
       // 清空方式比较特别，其实直接 O(n)清空也不会 tle,就当防伪标记了...
        for(auto [x,y]:tmp) vis[x][y]=0;
        tmp.clear();
        //for(int j=1;j<=n;j++) vis[j][0]=vis[j][1]=0;
        if(dfs(i)) ans++;
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