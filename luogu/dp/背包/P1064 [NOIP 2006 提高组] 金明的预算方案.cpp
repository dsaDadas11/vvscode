/*
 * @Author: dsaDadas11
 * @Date: 2025-09-29 20:46:16
 * @LastEditTime: 2025-09-29 20:47:43
 * @Description: go for it!
 */
/*
 因为体积都是 10的倍数，因此除以 10再算贡献，最后算出来的答案再乘以 10
 本来 1.2s T了，现在 125ms过了，甚至更加优秀
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=4e4+7;
constexpr int M=2e3+7;
int n,m;
int v[64],w[64];
vector<int> g[64];
int f[64][N];
void dfs(int u)
{
    for(int i=n;i>=v[u];i--) f[u][i]=w[u];
    for(auto s:g[u])
    {
        dfs(s);
        for(int j=n;j>=v[u];j--)
        {
            for(int k=0;k<=j-v[u];k++)
            {
                f[u][j]=max(f[u][j],f[u][j-k]+f[s][k]);
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    n/=10;
    int u;
    for(int i=1;i<=m;i++)
    {
        cin>>v[i]>>w[i]>>u;
        v[i]/=10;
        g[u].push_back(i);
        w[i]*=v[i];
    }
    dfs(0);
    cout<<f[0][n]*10<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}