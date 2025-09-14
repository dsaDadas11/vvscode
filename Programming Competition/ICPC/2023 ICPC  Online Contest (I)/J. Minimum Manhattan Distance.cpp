/*
 * @Author: dsaDadas11
 * @Date: 2025-09-05 18:50:12
 * @LastEditTime: 2025-09-05 18:50:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
    double x0,y0,x1,y1;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    x0=1.0*(a+c)/2,y0=1.0*(b+d)/2;

    cin>>a>>b>>c>>d;
    x1=1.0*(a+c)/2,y1=1.0*(b+d)/2;
    double q2r=sqrt(1.0*((a-c)*(a-c)+(b-d)*(b-d))/2);

    cout<<fixed<<setprecision(8)<<fabs(x0-x1)+fabs(y0-y1)-q2r<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}