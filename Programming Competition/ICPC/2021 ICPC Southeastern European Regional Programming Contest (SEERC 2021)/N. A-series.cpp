/*
 * @Author: dsaDadas11
 * @Date: 2025-09-10 19:13:28
 * @LastEditTime: 2025-09-10 19:13:37
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
int a[N],b[N];
void solve()
{
    cin>>n;
    n++;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int ans=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]>=b[i]) continue;
        int tmp=(b[i]-a[i]+1)/2;
        ans+=tmp;
        a[i-1]-=tmp;
    }
    if(a[0]<0) cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}