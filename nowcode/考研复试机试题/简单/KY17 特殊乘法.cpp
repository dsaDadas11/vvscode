/*
 * @Author: dsaDadas11
 * @Date: 2026-01-29 17:07:34
 * @LastEditTime: 2026-01-29 17:07:42
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string a,b;
void solve()
{
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            ans+=(a[i]-'0')*(b[j]-'0');
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>a>>b){solve();}
    return 0;
}