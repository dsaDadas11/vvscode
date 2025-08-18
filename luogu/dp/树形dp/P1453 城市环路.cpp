/*
 * @Author: dsaDadas11
 * @Date: 2025-08-15 13:11:04
 * @LastEditTime: 2025-08-18 11:15:02
 * @Description: go for it!
 */
/*
 解法一：并查集断边
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
double k;
int p[N],fa[N];
vector<int> g[N];
int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
int dp[N][2];
void dfs(int u,int fax)
{
    dp[u][1]=p[u],dp[u][0]=0;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs(v,u);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][1],dp[v][0]);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i],fa[i]=i;
    int u,v;
    int s=0,t=0;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v;
        u++,v++;
        int fax=find_fa(u),fay=find_fa(v);
        if(fax==fay)
        {
            s=u,t=v;
            continue;
        }
        fa[fax]=fay;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>k;
    int ans=0;
    dfs(s,0);
    ans=max(ans,dp[s][0]);
    dfs(t,0);
    ans=max(ans,dp[t][0]);

    cout<<fixed<<setprecision(1)<<1.0*ans*k<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

/*
 解法二：树形 dp + 环形 dp
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
double k;
int p[N];
vector<int> g[N];
int f[N][2],dp[N][2];
int loop[N],m;
int dep[N],fa[N];
bool vis[N];
void find_loop(int u)
{
	dep[u]=dep[fa[u]]+1;
	for(auto v:g[u])
	{
		if(v==fa[u]) continue;
		if(!dep[v]) // 还没遍历到这点
		{
			fa[v]=u;
			find_loop(v);
		}
		else if(dep[v]<dep[u]) // 深度比父节点小，肯定有环，并且环开头是在v
		{
			for(int i=u;;i=fa[i])
			{
				loop[++m]=i;
				vis[i]=1;
				if(i==v) break;
			}
		}
	}
}
void dfs1(int u,int fax)
{
    f[u][0]=0,f[u][1]=p[u];
    for(auto v:g[u])
    {
        if(v==fax) continue;
        if(vis[v]) continue;
        dfs1(v,u);
        f[u][0]+=max(f[v][1],f[v][0]);
        f[u][1]+=f[v][0];
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    int u,v;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v;
        u++,v++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>k;

    find_loop(1);
    for(int i=1;i<=m;i++)
    {
        dfs1(loop[i],0);
    }

    memset(dp,-0x3f,sizeof dp);
    dp[1][0]=f[loop[1]][0]; // 不选 loop[1]节点
    for(int i=2;i<=m;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+f[loop[i]][0];
        dp[i][1]=dp[i-1][0]+f[loop[i]][1];
    }
    int ans=max(dp[m][0],dp[m][1]);

    memset(dp,-0x3f,sizeof dp);
    dp[1][1]=f[loop[1]][1]; // 选 loop[1]节点
    for(int i=2;i<=m;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+f[loop[i]][0];
        dp[i][1]=dp[i-1][0]+f[loop[i]][1];
    }
    ans=max(ans,dp[m][0]);
    
    cout<<fixed<<setprecision(1)<<1.0*ans*k<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/

/*
解法三：基环树 dp + 异或判断正反向边，断边跑树形 dp
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
double k;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    int u,v;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v;
        u++,v++;
        add(u,v),add(v,u);
    }
    cin>>k;

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
    cout<<fixed<<setprecision(1)<<1.0*ans*k<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/