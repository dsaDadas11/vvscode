/*
 * @Author: dsaDadas11
 * @Date: 2025-03-08 10:59:11
 * @LastEditTime: 2025-03-08 10:59:22
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
int n;
void solve()
{
    cin>>n;
    int k=n/2;
    cout<<k*(k+1)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}