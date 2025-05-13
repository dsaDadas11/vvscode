/*
 * @Author: dsaDadas11
 * @Date: 2025-04-14 14:45:22
 * @LastEditTime: 2025-04-14 14:45:33
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
double a;
void solve()
{
    cin>>x>>y>>a;
    double tanc=(1.0*y/x-cos(a))/sin(a);
    double c=atan(tanc);
    cout<<round(1.0*x/cos(c))<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}