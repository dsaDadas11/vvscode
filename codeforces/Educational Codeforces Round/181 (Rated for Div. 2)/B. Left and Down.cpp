/*
 * @Author: dsaDadas11
 * @Date: 2025-07-22 23:17:43
 * @LastEditTime: 2025-07-22 23:17:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b,k;
void solve()
{
    cin>>a>>b>>k;
    if(a/gcd(a,b)<=k&&b/gcd(a,b)<=k) cout<<"1"<<endl;
    else cout<<"2"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}