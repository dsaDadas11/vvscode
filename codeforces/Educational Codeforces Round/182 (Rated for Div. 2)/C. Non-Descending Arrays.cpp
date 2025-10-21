/*
 * @Author: dsaDadas11
 * @Date: 2025-09-22 20:07:55
 * @LastEditTime: 2025-09-22 20:08:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
int a[107],b[107];
int f[107][2]; // 第 i个位置 换/不换 的，使 [1,i]不递减的方案数
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) f[i][0]=f[i][1]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    f[1][0]=f[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        // 0 0
        if(a[i]>=a[i-1]&&b[i]>=b[i-1]) f[i][0]+=f[i-1][0];

        // 0 1
        if(a[i]>=b[i-1]&&b[i]>=a[i-1]) f[i][1]+=f[i-1][0];

        // 1 0
        if(a[i]>=b[i-1]&&b[i]>=a[i-1]) f[i][0]+=f[i-1][1];

        // 1 1
        if(a[i]>=a[i-1]&&b[i]>=b[i-1]) f[i][1]+=f[i-1][1];

        f[i][1]%=mod,f[i][0]%=mod;
    }

    cout<<(f[n][0]+f[n][1])%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}