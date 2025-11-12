/*
 * @Author: dsaDadas11
 * @Date: 2025-11-12 20:26:38
 * @LastEditTime: 2025-11-12 20:28:32
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int inf=1e16;
int n;
int a[N],f[N];
int dp(int l,int r)
{
    f[l-1]=0,f[l]=inf;
    for(int i=l+1;i<=r;i++)
    {
        f[i]=f[i-2]+abs(a[i]-a[i-1]);
        if(i>=l+2)
        {
            f[i]=min(f[i],f[i-3]+max({a[i],a[i-1],a[i-2]})-min({a[i],a[i-1],a[i-2]}));
        }
    }

    return f[r];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=min(2LL,n);i++)
    {
        a[i+n]=a[i];
    }

    int ans=inf;
    for(int i=1;i<=min(2LL,n)+1;i++)
    {
        ans=min(ans,dp(i,i+n-1));
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}