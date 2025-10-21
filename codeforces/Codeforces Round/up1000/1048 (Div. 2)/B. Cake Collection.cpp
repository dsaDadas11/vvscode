/*
 * @Author: dsaDadas11
 * @Date: 2025-09-23 10:57:17
 * @LastEditTime: 2025-09-23 10:57:26
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
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(m<=n)
    {
        int tim=1;
        int ans=0;
        for(int i=n-m+1;i<=n;i++)
        {
            ans+=a[i]*tim;
            tim++;
        }
        cout<<ans<<endl;
    }
    else
    {
        int ans=(m-n+1)*a[1];
        int tim=m-n+1;
        for(int i=2;i<=n;i++)
        {
            tim++;
            ans+=a[i]*tim;
        }
        cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}