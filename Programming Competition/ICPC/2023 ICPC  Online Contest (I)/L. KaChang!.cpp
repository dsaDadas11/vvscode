/*
 * @Author: dsaDadas11
 * @Date: 2025-09-04 22:06:33
 * @LastEditTime: 2025-09-04 22:06:42
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k,t;
void solve()
{
    cin>>n>>k;
    int ans=2;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        ans=max(ans,(k+t-1)/k);
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