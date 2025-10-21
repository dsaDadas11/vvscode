/*
 * @Author: dsaDadas11
 * @Date: 2025-09-23 10:41:15
 * @LastEditTime: 2025-09-23 10:41:24
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b;
void solve()
{
    cin>>a>>b;
    if(a==b)
    {
        cout<<0<<endl;
        return;
    }
    if(a<b) swap(a,b);
    if(a%b==0) cout<<1<<endl;
    else cout<<2<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}