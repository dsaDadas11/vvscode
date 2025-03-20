/*
 * @Author: dsaDadas11
 * @Date: 2025-03-15 13:03:29
 * @LastEditTime: 2025-03-15 13:03:41
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int sq(int x)
{
    return (x/2)*((x+1)/2);
}
void solve()
{
    cin>>n>>k;
    if(k&1) return cout<<"0"<<endl,void();
    k/=2;
    cout<<(n%k)*sq(n/k+1)+(k-n%k)*sq(n/k)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}