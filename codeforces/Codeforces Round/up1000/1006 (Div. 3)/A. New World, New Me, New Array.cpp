/*
 * @Author: dsaDadas11
 * @Date: 2025-03-11 20:30:13
 * @LastEditTime: 2025-03-11 20:30:36
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k,p;
void solve()
{
    cin>>n>>k>>p;
    int ans=(abs(k)+p-1)/p;
    if(ans>n) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}