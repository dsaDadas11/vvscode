/*
 * @Author: dsaDadas11
 * @Date: 2025-03-21 18:52:48
 * @LastEditTime: 2025-03-21 18:52:59
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
int x,y;
int ans;
void solve()
{
    cin>>n>>m;
    int miu=1e18,mxu=-1e18,miv=1e18,mxv=-1e18;
    ans=1e18;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        miu=min(miu,x+y);
        mxu=max(mxu,x+y);

        miv=min(miv,x-y);
        mxv=max(mxv,x-y);
    }
    
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        int dx=max({mxu-x-y,x+y-miu,mxv-x+y,x-y-miv});
        ans=min(ans,dx);
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