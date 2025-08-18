/*
 * @Author: dsaDadas11
 * @Date: 2025-07-28 15:54:26
 * @LastEditTime: 2025-07-28 15:54:36
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x;
void solve()
{
    cin>>x;
    int ans=9;
    while(x)
    {
        ans=min(ans,x%10);
        x/=10;
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