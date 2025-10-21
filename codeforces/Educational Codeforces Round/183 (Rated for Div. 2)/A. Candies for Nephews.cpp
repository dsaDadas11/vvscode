/*
 * @Author: dsaDadas11
 * @Date: 2025-10-10 15:11:08
 * @LastEditTime: 2025-10-10 15:11:16
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
    cin>>n;
    if(n%3==0) return cout<<0<<endl,void();
    int x=(n/3+1)*3;
    cout<<x-n<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}