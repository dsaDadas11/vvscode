/*
 * @Author: dsaDadas11
 * @Date: 2025-10-15 21:41:23
 * @LastEditTime: 2025-10-15 21:43:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=1e8+3;
constexpr int M=2e3+7;
int a[N],p[N],cnt;
void init()
{
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&(ll)p[j]*i<N;j++)
        {
            a[p[j]*i]=p[j];
            if(i%p[j]==0) break;
        }
    }
}
int n;
void solve()
{
    cin>>n;
    if(a[n]==0)
    {
        cout<<n<<endl;
        return;
    }
    int ans=0;
    while(a[n])
    {
        ans^=a[n];
        n/=a[n];
    }
    ans^=n;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}