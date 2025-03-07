/*
 * @Author: dsaDadas11
 * @Date: 2025-03-07 17:12:11
 * @LastEditTime: 2025-03-07 17:12:21
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
string s;
void solve()
{
    cin>>n>>s;
    s=' '+s;
    int ans=0;
    char st='0';
    for(int i=1;i<=n;i++)
    {
        if(s[i]==st) continue;
        ans++;
        st=s[i];
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}