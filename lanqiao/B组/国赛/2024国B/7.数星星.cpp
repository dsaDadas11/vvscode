/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 16:14:52
 * @LastEditTime: 2025-06-07 16:18:51
 * @Description: go for it!
 */
/*
 解题思路：
 以 u为根节点，d[u]为度数的树能包含的节点 (注意是 G树中的度数，不是总的)
 那么我们只需考虑 u和与 u相连的节点即可
 设选 j个节点 (不包含 u)
 sum[j+1] += C(d[u],j);
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n;
int d[N],f[N],g[N];
int sum[N];
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=(ans*x)%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int niyuan(int x)
{
    return quickpow(x,mod-2);
}
void init()
{
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%mod;
    }
    g[N-1]=niyuan(f[N-1]);
    for(int i=N-1;i>=1;i--)
    {
        g[i-1]=g[i]*i%mod;
    }
}
int C(int n,int m)
{
    if(m>n||m<0) return 0;
    return ((f[n]*g[m])%mod)*g[n-m]%mod;
}
void solve()
{
    cin>>n;
    int u,v,l,r;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        d[u]++,d[v]++;
    }
    cin>>l>>r;
    sum[1]=n,sum[2]=n-1;
    for(int i=1;i<=n;i++)
    {
        // 选多少个节点
        for(int j=2;j<=d[i];j++)
        {
            sum[j+1]=(sum[j+1]+C(d[i],j))%mod;
        }
    }
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        ans=(ans+sum[i])%mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}