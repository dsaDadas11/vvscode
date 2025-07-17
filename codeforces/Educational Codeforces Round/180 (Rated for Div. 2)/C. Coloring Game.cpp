/*
 * @Author: dsaDadas11
 * @Date: 2025-07-17 16:30:23
 * @LastEditTime: 2025-07-17 16:30:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            int r=lower_bound(a+1+j,a+1+n,a[i]+a[j])-a;
            r--;
            if(r<j+1) continue;
            int l=upper_bound(a+1+j,a+1+n,a[n]-a[i]-a[j])-a;
            if(l>r) continue;
            ans+=r-l+1;
        }
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