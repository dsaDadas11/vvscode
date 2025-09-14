/*
 * @Author: dsaDadas11
 * @Date: 2025-08-21 11:15:13
 * @LastEditTime: 2025-08-21 11:15:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
int f[N],q[N];
void solve()
{
    cin>>n>>k;
    k++;
    int ans=1e16,sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];

    int h=1,t=0;
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&f[q[t]]>=f[i-1]) t--;
        q[++t]=i-1;
        if(i-q[h]>k) h++;
        f[i]=a[i]+f[q[h]];
    }

    for(int i=n-k+1;i<=n;i++) ans=min(ans,f[i]);
    cout<<sum-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}