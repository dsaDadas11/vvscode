/*
 * @Author: dsaDadas11
 * @Date: 2025-04-07 18:39:39
 * @LastEditTime: 2025-04-07 18:39:49
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
int n;
int ans[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ans[i]=max((i-1)*2,(n-i)*2);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}