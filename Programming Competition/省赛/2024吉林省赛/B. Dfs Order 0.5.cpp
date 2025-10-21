/*
 * @Author: dsaDadas11
 * @Date: 2025-10-06 14:41:32
 * @LastEditTime: 2025-10-06 14:41:56
 * @Description: go for it!
 */
/*
 奇偶转化，有点绕。。
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
int sz[N];
int f[N][2];
vector<int> g[N];
void dfs(int u,int fax)
{
    sz[u]=1;
    f[u][0]=0,f[u][1]=a[u];
    int odd=0;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]&1) odd++;
    }
    if(odd)
    {
        int sum0=0,sum1=0;
        vector<int> d;
        for(auto v:g[u])
        {
            if(v==fax) continue;
            if(sz[v]&1) sum1+=f[v][0],d.push_back(f[v][1]-f[v][0]);
            else sum0+=max(f[v][0],f[v][1]);
        }
        sort(d.begin(),d.end(),greater<>());
        f[u][0]+=sum0,f[u][1]+=sum0;
        int len=odd/2+odd%2,tmp=0;
        for(int i=0;i<len;i++) tmp+=d[i];
        f[u][0]+=sum1+tmp;
        len=odd/2,tmp=0;
        for(int i=0;i<len;i++) tmp+=d[i];
        f[u][1]+=sum1+tmp;
    }
    else
    {
        for(auto v:g[u])
        {
            if(v==fax) continue;
            f[u][0]+=f[v][1];
            f[u][1]+=f[v][0];
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
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
    cout<<f[1][0]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}