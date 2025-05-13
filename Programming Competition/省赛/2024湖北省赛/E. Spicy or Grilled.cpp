/*
 * @Author: dsaDadas11
 * @Date: 2025-05-02 13:40:55
 * @LastEditTime: 2025-05-02 13:41:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x,a,b;
void solve()
{
    cin>>n>>x>>a>>b;
    cout<<x*b+(n-x)*a<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}