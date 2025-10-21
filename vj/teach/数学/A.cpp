/*
 * @Author: dsaDadas11
 * @Date: 2025-10-11 19:21:44
 * @LastEditTime: 2025-10-11 19:21:55
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
bool check(int x)
{
    if(x==1) return 0;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i) continue;
        return 0;
    }
    return 1;
}
int n,x;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(check(x)) cout<<x<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}