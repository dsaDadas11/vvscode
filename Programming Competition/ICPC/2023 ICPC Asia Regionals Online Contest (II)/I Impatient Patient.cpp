/*
 * @Author: dsaDadas11
 * @Date: 2025-09-12 11:24:09
 * @LastEditTime: 2025-09-12 17:13:24
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int m=100000;
int n;
int a[N];
double p[N],f[N];
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        p[i]=1.0*p[i]/m;
    }
    for(int i=0;i<=n;i++) f[i]=0;

    double ans=n;
    for(int i=0;i<n;i++)
    {
        if(p[i]==0) continue;
        // f[i]表示选 i为最优策略，那么之前 [0,i-1]都不选，直接修养
        // 成功次数的期望需要推导
        f[i]=i+1+(1/p[i]-1)*(i-a[i]+1);
        ans=min(ans,f[i]);
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}