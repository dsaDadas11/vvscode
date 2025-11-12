/*
 * @Author: dsaDadas11
 * @Date: 2025-10-28 21:48:47
 * @LastEditTime: 2025-10-28 21:49:22
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n,m;
int w[N];
int dfn[N],sz[N];
int a[N];
vector<int> g[N];
int f[N][20],lg[N];
void init()
{
    // 避免浮点运算，加快速度
    lg[1]=0;
    for(int i=2;i<N;i++)
    {
        lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
    }
}
int query(int l,int r)
{
    int k=lg[r-l+1];
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
void dfs(int u,int fax)
{
    dfn[++m]=u;
    sz[u]=1;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
void solve()
{
    cin>>n;
    m=0;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        g[i].clear();
    }

    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++)
    {
        a[i]=w[dfn[i]];
    }
    for(int i=1;i<=n;i++) f[i][0]=a[i];
    for(int j=1;j<20;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }

    vector<pair<int,int> > b(n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]={a[i],i};
    }
    sort(b.begin()+1,b.end(),greater<pair<int,int> >());

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int p=b[i].second;
        int l1=1,r1=p-1;
        int l2=p+sz[dfn[p]],r2=n;
        int maxn=0;
        if(l1<=r1) maxn=max(maxn,query(l1,r1));
        if(l2<=r2) maxn=max(maxn,query(l2,r2));

        if(maxn>b[i].first)
        {
            ans=dfn[p];
            break;
        }
    }

    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}