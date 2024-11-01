/*
 * @Author: dsaDadas11
 * @Date: 2024-10-02 22:32:15
 * @LastEditTime: 2024-10-02 23:16:07
 * @Description: go for it!
 */
/*
 解题思路：
 这道题的sg不是简单的无向图游戏的sg,因为其中包括删除节点和删除边，
 因此一个树的sg值为各个删除节点或删除边的子状态的sg值的mex运算
 比如n=1时sg=1,n=2时由n=1转移过来，sg值为1
 n=3时 设树结构为 1->2->3 ,那么可由(1->2,3),(1,3),(2->3)三个状态转移过来，它们的sg值分别为 0 0 2,所以n=3为1
 以此类推n为奇数的时候sg为1，n为偶数时sg为2
 (需要注意的是当子状态又有多个子状态时用mex运算，没有子状态时就是其sg值)

 然后我们存一下树的大小和每个节点的树根，模拟删除节点和删除边的操作就好了
 具体的看代码就懂了
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
vector<pair<int,int> > adj;
int fa[N];
int s[N]; // 记录每个节点的sg值
int sz[N]; // 记录以节点i为根的树的大小
int rt[N]; // 记录节点的根节点
int sg,ans;
void dfs(int u,int f,int root)
{
    fa[u]=f,rt[u]=root;
    sz[u]=1;
    for(auto v:g[u])
    {
        if(v==f) continue;
        dfs(v,u,root);
        sz[u]+=sz[v];
    }
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
        adj.push_back({u,v});
    }
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==0)
        {
            dfs(i,0,i);
            if(sz[i]%2) sg^=1,s[i]=1;
            else sg^=2,s[i]=2;
        }
    }
    // 删节点
    for(int i=1;i<=n;i++)
    {
        int t=sg;
        t^=s[rt[i]]; // 先将i所在的整棵树删去
        // 然后再加子树
        for(auto v:g[i])
        {
            if(v==fa[i])
            {
                if((sz[rt[i]]-sz[i])%2) t^=1;
                else t^=2;
            }
            else
            {
                if(sz[v]%2) t^=1;
                else t^=2;
            }
        }
        if(t==0) ans++;
    }
    // 删边
    for(auto [x,y]:adj)
    {
        int t=sg;
        t^=s[rt[u]]; // 先将整棵树删去
        // 删完边后变成两个子树
        if(v==fa[u]) swap(u,v);
        if((sz[rt[u]]-sz[v])%2) t^=1;
        else t^=2;
        if(sz[v]%2) t^=1;
        else t^=2;
        if(t==0) ans++;
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