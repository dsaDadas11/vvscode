/*
 * @Author: dsaDadas11
 * @Date: 2026-01-21 15:21:35
 * @LastEditTime: 2026-01-21 15:21:41
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
    int cnt=0;
    while(n>1)
    {
        if(n&1) n=3*n+1;
        n/=2;
        cnt++;
    }
    cout<<cnt<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>n){solve();}
    return 0;
}