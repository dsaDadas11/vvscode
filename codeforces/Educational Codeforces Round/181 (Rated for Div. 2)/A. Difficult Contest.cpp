/*
 * @Author: dsaDadas11
 * @Date: 2025-07-22 23:16:56
 * @LastEditTime: 2025-07-22 23:17:05
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
void solve()
{
    cin>>s;
    sort(s.begin(),s.end(),greater<>());
    cout<<s<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}