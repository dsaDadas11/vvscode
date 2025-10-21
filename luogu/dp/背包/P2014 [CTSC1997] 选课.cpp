/*
 * @Author: dsaDadas11
 * @Date: 2025-08-13 10:43:16
 * @LastEditTime: 2025-09-29 19:36:07
 * @Description: go for it!
 */
/*
 树上背包 n^3 版本
 下面有 n^2版本
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=3e2+5;
int n,m;
int s[M],sz[M];
vector<int> g[M];
int dp[M][M][M];
void dfs(int u)
{
    sz[u]=1;
    dp[u][1][1]=s[u],dp[u][1][0]=0;

    for(int i=2;i<g[u].size()+2;i++)
    {
        int v=g[u][i-2];
        dfs(v);
        sz[u]+=sz[v];
        for(int j=0;j<=sz[u];j++) // 在 u里选
        {
            for(int k=0;k<=min(j-1,sz[v]);k++) // 在 v里选
            {
                dp[u][i][j]=max(dp[u][i][j],dp[u][i-1][j-k]+dp[v][g[v].size()+1][k]); // 包括根节点，得+1
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>s[i];
        g[x].push_back(i);
    }
    dfs(0);
    cout<<dp[0][g[0].size()+1][m+1];
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=3e2+5;
int n,m;
int s[M],sz[M];
vector<int> g[M];
int dp[M][M]; // j只和前一位状态有关，可以去掉
void dfs(int u)
{
    sz[u]=1;
    dp[u][1]=s[u],dp[u][0]=0;

    for(int i=1;i<g[u].size()+1;i++)
    {
        int v=g[u][i-1];
        dfs(v);
        for(int j=sz[u];j>=0;j--) // 在 u里选,反着遍历
        {
            for(int k=sz[v];k>=0;k--) // 在 v里选,反着遍历
            {
                if(j==0&&k>0) continue; // 状态不合法
                dp[u][j+k]=max(dp[u][j+k],dp[u][j]+dp[v][k]); // 包括根节点，得+1
            }
        }
        sz[u]+=sz[v];
    }
}
void solve()
{
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>s[i];
        g[x].push_back(i);
    }
    dfs(0);
    cout<<dp[0][m+1];
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

用后序遍历实现，需要依赖子树的条件
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=3e2+5;
int n,m;
int s[M],sz[M];
vector<int> g[M];
int dp[M][M]; // dp[i][j]表示当前节点 i和自己前面兄弟中选 j个节点的最大值
int num[M],cnt; // 后序遍历的编号对应原来的节点编号
void dfs(int u)
{
    sz[u]=1;
    for(auto v:g[u])
    {
        dfs(v);
        sz[u]+=sz[v];
    }
    num[++cnt]=u;
}
void solve()
{
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>s[i];
        g[x].push_back(i);
    }
    dfs(0);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j>0) dp[i][j]=max(dp[i-1][j-1]+s[num[i]],dp[i-sz[num[i]]][j]);
            else dp[i][j]=dp[i-sz[num[i]]][j]; // 跳过子树
        }
    }
    cout<<dp[n][m];
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
20250929重新学了一遍，之前的代码看不懂
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int f[307][307]; // 为选择 u节点，体积为 j时的最大价值
vector<int> g[307];
int w[307],v[307];
void dfs(int u) // m为最大体积
{
    for(int i=v[u];i<=m;i++) f[u][i]=w[u];// 选 u节点

    for(auto s:g[u])
    {
        dfs(s); // 递归子节点
        for(int j=m;j>=v[u];j--)// 父节点要选，因此体积 >=v[u]
        {
            for(int k=0;k<=j-v[u];k++)// 分配
            {
                f[u][j]=max(f[u][j],f[u][j-k]+f[s][k]);
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    m++; // 多加一个 0节点
    int rt=0;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p>>w[i];
        g[p].push_back(i);
    }

    dfs(0);
    cout<<f[0][m]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/