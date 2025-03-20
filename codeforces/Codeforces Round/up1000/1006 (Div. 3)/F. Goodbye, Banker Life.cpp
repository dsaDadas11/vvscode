/*
 * @Author: dsaDadas11
 * @Date: 2025-03-18 21:53:47
 * @LastEditTime: 2025-03-18 21:53:57
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cout<<k*(((n-1)&(i-1))==i-1)<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}