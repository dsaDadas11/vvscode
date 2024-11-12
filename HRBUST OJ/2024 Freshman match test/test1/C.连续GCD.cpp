/*
 * @Author: dsaDadas11
 * @Date: 2024-10-05 21:16:41
 * @LastEditTime: 2024-10-05 21:16:46
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string l,r;
void solve()
{
    cin>>l>>r;
    if(l==r) cout<<l<<endl;
    else cout<<"1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}