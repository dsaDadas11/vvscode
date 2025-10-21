/*
 * @Author: dsaDadas11
 * @Date: 2025-09-21 21:46:06
 * @LastEditTime: 2025-09-22 10:22:44
 * @Description: go for it!
 */
/*
 解题思路：
 我们可以算出每个点的点权，然后跑 prim算法，但是关键在于怎么保证连通性
 我们设已经连上的一条边的两个端点为 [u,v]，并且 u已经在生成树中，v是经过排序后最小权值的，马上要加进生成树的点。
 要清楚此时是虚拟连边，很有可能这个点在 set里面取出之前已经连上虚拟边了，因此我们要判断 set里面是否还存在这个点 v，
 如果存在，那么我们就能连上 [u,v]，并且加上它两的贡献，然后我们就可以对 u和 v进行下一轮的虚拟连边（保证每个点都有一条出边，使得生成树可以持续生长）

 要注意的是：
 se自带的二分查找为：auto pos=se.lower_bound(k-x);
 如果用下面这个，会超时，时间复杂度为 (log)^2吧
 auto pos=lower_bound(se.begin(),se.end(),k-x);
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
struct edge
{
    int w,v,u;
    bool operator<(const edge &a) const
    {
        return w>a.w;
    }
};
multiset<int> se;
int get(int x)
{
    auto pos=se.lower_bound(k-x);
    if(pos==se.end()) pos=se.begin();
    return *pos;
}
void solve()
{
    cin>>n>>k;
    se.clear();
    priority_queue<edge> pq;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        se.insert(x%k);
    }

    x=*se.begin();
    se.erase(se.begin());

    y=get(x);
    pq.push({(x+y)%k,y,x});

    int ans=0;
    while(!pq.empty())
    {
        auto [w,v,u]=pq.top();
        pq.pop();

        if(!se.count(v)) // 没有这个节点
        {
            continue;
        }

        se.erase(se.find(v)); // 有就连边，并且把 v从 se中删掉

        ans+=w;
        if(se.empty()) break;

        y=get(v);
        pq.push({(y+v)%k,y,v});

        y=get(u);
        pq.push({(y+u)%k,y,u});
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}