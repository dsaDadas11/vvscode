/*
 * @Author: dsaDadas11
 * @Date: 2025-04-12 19:22:14
 * @LastEditTime: 2025-04-12 19:22:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
void solve()
{
    int ans=1;
    for(int i=1;i<=1012;i++)
    {
        ans<<=1;
        ans%=mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}