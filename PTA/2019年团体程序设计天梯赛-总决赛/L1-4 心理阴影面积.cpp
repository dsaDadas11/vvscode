/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 19:49:16
 * @LastEditTime: 2025-04-15 19:49:23
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
    cout<<abs(100*50-x*50-(100-y)*50)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}