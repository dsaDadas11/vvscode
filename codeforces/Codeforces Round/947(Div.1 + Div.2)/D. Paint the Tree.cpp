/*
 一开始双向广搜代码写错了，应该是A先扩张一圈，B才能扩张，而不是A扩一个，B扩一个
 解题思路：
 我们先让A,B两点汇合，汇合完了之后，两个点可以看作一个，然后就能跑最短路了
 怎么汇合? 我们用双向广搜从A,B一直扩张直到相遇
 那最短路怎么求? 
 有一个结论：在树中的一个节点跑遍树上所有点的最短路为 2*(n-1)-max_dis
 其中max_dis为这个节点到端点的最远距离
 其实好像就是每一条路都要走两遍，找到最远距离后让最远距离走一遍即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int a,b;
int st; //相遇后从这个点开始走
bool visa[N],visb[N];
int maxn; // 最大路径
int stp; // 刚开始的相遇路径
vector<int> g[N];
struct op
{
    int u,fa,step;
};
void bfs_meet()
{
    queue<op> qa,qb;
    qa.push({a,0,0});
    qb.push({b,0,0});
    visa[a]=1,visb[b]=1;
    while(!qa.empty()&&!qb.empty())
    {
        // 先搜A
        int cnt=qa.size();
        for(int i=1;i<=cnt;i++)
        {
            auto [ua,faa,stepa]=qa.front();
            qa.pop();
            for(auto va:g[ua])
            {
                if(va==faa) continue;
                if(visa[va]) continue;
                visa[va]=1;
                if(visb[va]) //找到了这个相遇点,但是为异步
                {
                    st=ua; // st为父节点
                    stp=stepa+1;
                    return;
                }
                qa.push({va,ua,stepa+1});
            }
        }
        // 再搜B
        cnt=qb.size();
        for(int i=1;i<=cnt;i++)
        {
            auto [ub,fab,stepb]=qb.front();
            qb.pop();
            for(auto vb:g[ub])
            {
                if(vb==fab) continue;
                if(visb[vb]) continue;
                visb[vb]=1;
                if(visa[vb]) //找到了这个相遇点,并且为同步
                {
                    st=vb; // st为该节点
                    stp=stepb+1;
                    return;
                }
                qb.push({vb,ub,stepb+1});
            }
        }
    }
}
void dfs(int u,int fa,int step) // 找最大路径
{
    maxn=max(maxn,step);
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u,step+1);
    }
}
void solve()
{
    cin>>n;
    cin>>a>>b;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(a==b) st=a;
    else bfs_meet();
    dfs(st,0,0);
    cout<<2*(n-1)-maxn+stp<<endl;
    maxn=0,st=0,stp=0;
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        visa[i]=visb[i]=0;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}