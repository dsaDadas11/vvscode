/*
 * @Author: dsaDadas11
 * @Date: 2024-10-03 22:36:07
 * @LastEditTime: 2024-10-03 22:36:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int a[N],b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n+1;i++) cin>>b[i];
    int ans=0;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        ans+=abs(a[i]-b[i]);
        if(min(a[i],b[i])<=b[n+1]&&b[n+1]<=max(a[i],b[i])) flag=1;
    }
    ans++;
    if(!flag)
    {
        int mx=1e10;
        for(int i=1;i<=n;i++)
        {
            mx=min({abs(a[i]-b[n+1]),abs(b[i]-b[n+1]),mx});
        }
        ans+=mx;
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