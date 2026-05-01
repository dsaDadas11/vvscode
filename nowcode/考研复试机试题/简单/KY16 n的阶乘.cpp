/*
 * @Author: dsaDadas11
 * @Date: 2026-01-29 17:04:44
 * @LastEditTime: 2026-01-29 17:04:52
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
void solve()
{
    int ans=1;
    for(int i=1;i<=n;i++) ans*=i;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>n){solve();}
    return 0;
}