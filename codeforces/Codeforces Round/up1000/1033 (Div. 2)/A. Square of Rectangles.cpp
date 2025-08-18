/*
 * @Author: dsaDadas11
 * @Date: 2025-07-22 15:45:51
 * @LastEditTime: 2025-07-22 15:46:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a1,b1,a2,b2,a3,b3;
void solve()
{
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    bool ok=0;
    if(a1==a2&&a2==a3)
    {
        if(b1+b2+b3==a1) ok=1;
    }
    if(b1==b2&&b2==b3)
    {
        if(a1+a2+a3==b1) ok=1;
    }
    
    if(a1==a2+a3)
    {
        if(b2==b3&&b2+b1==a1) ok=1;
    }
    if(b1==b2+b3)
    {
        if(a2==a3&&a2+a1==b1) ok=1;
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}