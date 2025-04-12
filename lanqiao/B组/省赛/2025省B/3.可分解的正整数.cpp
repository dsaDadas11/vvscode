/*
 * @Author: dsaDadas11
 * @Date: 2025-04-12 19:25:54
 * @LastEditTime: 2025-04-12 19:26:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
int ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x!=1) ans++;
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