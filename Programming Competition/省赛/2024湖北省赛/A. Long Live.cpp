/*
 * @Author: dsaDadas11
 * @Date: 2025-05-02 13:49:37
 * @LastEditTime: 2025-05-02 13:49:44
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y;
void solve()
{
    cin>>x>>y;
    cout<<"1 "<<x*y/(gcd(x,y)*gcd(x,y))<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}