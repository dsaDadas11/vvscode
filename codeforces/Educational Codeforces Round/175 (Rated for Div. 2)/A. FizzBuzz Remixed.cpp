/*
 * @Author: dsaDadas11
 * @Date: 2025-03-18 12:18:36
 * @LastEditTime: 2025-03-18 12:18:46
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
    cin>>n;
    int yu=n%15;
    int ans=(n/15)*3;
    ans+=min(yu+1,3LL);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}