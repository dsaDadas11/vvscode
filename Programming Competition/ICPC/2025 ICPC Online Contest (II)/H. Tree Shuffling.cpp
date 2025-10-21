/*
 * @Author: dsaDadas11
 * @Date: 2025-09-15 15:45:37
 * @LastEditTime: 2025-09-15 21:37:31
 * @Description: go for it!
 */
/*
 一条长度为 k的链的贡献原本是 fac[k]，但是会发现和 k-1链有重叠部分，即 a[k]在最后位置的方案有 fac[k-1]种，区间为 [1,k-1]
 并且还有 a[1]在第一位上，与后面的链也会重叠，也有方案数 fac[k-1]，区间为 [2,k]，多减的部分为 fac[k-2]，区间为 [2,k-1]

 官方解释：设两端为 x,y，如果有 a[x]=x或 a[y]=y，那么可以操作更短的链，因此要减去重复贡献 2*fac[k-1]，
 但是当 a[x]=x且 a[y]=y时贡献又多减了一次，因此要加回贡献 fac[k-2]

 我们可以枚举每一条链，算出它的方案数，时间复杂度为 O(n^2)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e3+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
vector<int> g[N];
int fac[N],dep[N];
void init()
{
    fac[0]=1;
    for(int i=1;i<N;i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
}
int ans;
vector<int> dfs(int u,int fax)
{
    vector<int> fap;
    dep[u]=dep[fax]+1;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        vector<int> sonp=dfs(v,u);
        for(auto l:fap)
        {
            for(auto r:sonp)
            {
                int k=dep[l]+dep[r]-2*dep[u]+1;
                ans+=((fac[k]-2*fac[k-1]%mod+fac[k-2])%mod+mod)%mod;
                ans%=mod;
            }
        }

        for(auto r:sonp) fap.push_back(r);
    }

    for(auto v:fap)
    {
        int k=dep[v]-dep[u]+1;
        ans+=((fac[k]-2*fac[k-1]%mod+fac[k-2])%mod+mod)%mod;
        ans%=mod;
    }
    fap.push_back(u);
    return fap;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear(),dep[i]=0;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans=0;
    dfs(1,0);
    cout<<(ans+1)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}

/*
 点分治求出各个链的长度
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e3+7;
constexpr int M=1e4+7;
constexpr int mod=998244353;
int n,m;
vector<pair<int,int> > g[N]; // v w
int del[N],sz[N],mxs,sum,root; // 求根
int dist[N],d[N],cnt; // 求距离
int ans[N],q[N],judge[N]; // 求路径
void get_root(int u,int fax)
{
    sz[u]=1;
    int s=0;
    for(auto [v,w]:g[u])
    {
        if(v==fax||del[v]) continue;
        get_root(v,u);
        sz[u]+=sz[v];
        s=max(s,sz[v]);
    }
    s=max(s,sum-sz[u]);
    if(s<mxs) mxs=s,root=u;
}
void get_dist(int u,int fax)
{
    dist[++cnt]=d[u];
    for(auto [v,w]:g[u])
    {
        if(v==fax||del[v]) continue;
        d[v]=d[u]+w;
        get_dist(v,u);
    }
}
void calc(int u)
{
    del[u]=judge[1]=1;
    int p=0;
    // 计算经过根 u的路径
    for(auto [v,w]:g[u])
    {
        if(del[v]) continue;
        // 计算子树 v的各点到 u的距离
        cnt=0;
        d[v]=w;
        get_dist(v,u);
        // 枚举距离和
        for(int i=1;i<=cnt;i++)
        {
            for(int k=dist[i]+1;k<=n;k++)
            {
                ans[k]+=judge[k-dist[i]];
                ans[k]%=mod;
                if(judge[k-dist[i]]==0) break;
            }
        }
        // 记录合法距离
        for(int i=1;i<=cnt;i++)
        {
            q[++p]=dist[i]+1;
            judge[dist[i]+1]++;
        }
    }
    // 清空 judge
    for(int i=1;i<=p;i++) judge[q[i]]=0;
}
void divide(int u)
{
    // 计算经过根 u的路径
    calc(u);
    // 对 u子树进行分治
    for(auto [v,w]:g[u])
    {
        if(del[v]) continue;
        mxs=sum=sz[v];
        get_root(v,0); // 求根
        divide(root); // 分治
    }
}
void init()
{
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        del[i]=sz[i]=0;
        dist[i]=d[i]=0;
        ans[i]=q[i]=judge[i]=0; // 必须清空到 n+1，因为最大距离为 n+1
    }
    mxs=sum=root=0;
    cnt=0;
}
int fac[N];
void pre()
{
    fac[0]=1;
    for(int i=1;i<N;i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
}
void solve()
{
    cin>>n;
    init();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,1});
        g[v].push_back({u,1});
    }

    mxs=sum=n; // 第一次先找整棵树的重心
    get_root(1,0);
    divide(root);

    int res=1;
    for(int k=2;k<=n;k++)
    {
        if(ans[k]==0) break;
        res+=ans[k]*(fac[k]-2*fac[k-1]%mod+fac[k-2])%mod;
        res=(res%mod+mod)%mod;
    }
    cout<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/