/*
 * @Author: dsaDadas11
 * @Date: 2025-04-17 20:06:16
 * @LastEditTime: 2025-04-17 20:06:25
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
void solve()
{
    cin>>n>>k;
    int ans=0;
    if(n&1) ans++,n-=k;
    if(n<=0) return cout<<ans<<endl,void();
    ans+=ceil(1.0*n/(k-1));
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}