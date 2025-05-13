/*
 * @Author: dsaDadas11
 * @Date: 2025-04-18 18:34:24
 * @LastEditTime: 2025-04-18 18:34:32
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b,c,d,e;
void solve()
{
    cin>>a>>b>>c>>d>>e;
    cout<<a*b*c*d*(d-1)/2+a*b*c*d*e<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}