/*
 * @Author: dsaDadas11
 * @Date: 2026-01-19 17:54:14
 * @LastEditTime: 2026-01-19 17:54:47
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
    int len=s.size();
    reverse(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<len;i++)
    {
        int x=(s[i]-'0')*((1LL<<(i+1))-1);
        ans+=x;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>s){solve();}
    return 0;
}