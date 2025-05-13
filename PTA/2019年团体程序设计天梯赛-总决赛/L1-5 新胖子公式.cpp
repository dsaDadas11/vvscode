/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 19:51:55
 * @LastEditTime: 2025-04-15 19:52:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
double m,h;
void solve()
{
    cin>>m>>h;
    double d=m/(h*h);
    cout<<fixed<<setprecision(1);
    cout<<d<<endl;
    if(d>25) cout<<"PANG"<<endl;
    else cout<<"Hai Xing"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}