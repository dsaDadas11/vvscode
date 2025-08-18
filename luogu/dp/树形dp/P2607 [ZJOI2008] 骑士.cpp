/*
 * @Author: dsaDadas11
 * @Date: 2025-08-18 10:29:28
 * @LastEditTime: 2025-08-18 11:15:42
 * @Description: go for it!
 */
/*
 基环树 dp
 在有向图中建反向边，前提要求环是以有向边的形式存在
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int p[N];
vector<int> g[N];
int f[N][2],vis[N];
int r1,r2;
void find_loop(int u,int rt)
{
    vis[u]=1;
    for(auto v:g[u])
    {
        if(v==rt) // 找到环了
        {
            r1=u,r2=v;
            return;
        }
        if(vis[v]) continue;
        find_loop(v,rt);
    }
}
int dfs(int u,int rt)
{
    f[u][0]=0,f[u][1]=p[u];
    for(auto v:g[u])
    {
        if(v==rt) continue;
        dfs(v,rt);
        f[u][0]+=max(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
    return f[u][0]; //只能不选
}
void solve()
{
    cin>>n;
    int v;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>v;
        g[v].push_back(i);
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        r1=r2=0;
        find_loop(i,i);
        if(r1)
        {
            int res1=dfs(r1,r1);
            int res2=dfs(r2,r2);
            ans+=max(res1,res2);
        }
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

/*
 建双向边，用异或判断正反向边，并断边跑树形 dp
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct edge
{
    int v,ne;
} e[N<<1];
int h[N],w[N],idx=1; //从 2开始保证异或前后两条边为正反向边
void add(int a,int b)
{
    e[++idx]={b,h[a]};
    h[a]=idx;
}
int n;
int f[N][2],vis[N],br[N<<1]; //断边 break
int r1,r2;
bool find_loop(int u,int ine) //入边,注意是编号 idx，不是 u,v
{
    vis[u]=1;
    for(int i=h[u];i;i=e[i].ne)
    {
        if(i==(ine^1)) continue; //不能走到走回去(走反向边)
        int v=e[i].v;
        if(!vis[v])
        {
            if(find_loop(v,i)) return 1;
        }
        else
        {
            r1=u,r2=v;
            br[i]=1,br[i^1]=1;
            return 1;
        }
    }
    return 0;
}
int dfs(int u,int ine)
{
    vis[u]=1;
    f[u][0]=0,f[u][1]=w[u];
    for(int i=h[u];i;i=e[i].ne)
    {
        if(i==(ine^1)||br[i]) continue;
        int v=e[i].v;
        dfs(v,i);
        f[u][0]+=max(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
    return f[u][0];
}
void solve()
{
    cin>>n;
    int v;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v;
        add(i,v),add(v,i);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        r1=r2=0;
        find_loop(i,0);
        int res1=dfs(r1,0);
        int res2=dfs(r2,0);
        ans+=max(res1,res2);
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
*/