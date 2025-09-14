/*
 * @Author: dsaDadas11
 * @Date: 2025-08-21 10:57:50
 * @LastEditTime: 2025-08-21 10:57:59
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
int f[N]; // 选第 i个的最小代价
int q[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    int h=1,t=0; //尾  头
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&f[q[t]]>=f[i-1]) t--;
        q[++t]=i-1; // 位置不能换，会 wa
        if(i-q[h]>m) h++; // 保证连续 m个
        f[i]=a[i]+f[q[h]];
    }

    int ans=1e9;
    for(int i=n-m+1;i<=n;i++) ans=min(ans,f[i]);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}