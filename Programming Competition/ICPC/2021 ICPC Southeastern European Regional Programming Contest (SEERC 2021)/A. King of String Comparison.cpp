/*
 * @Author: dsaDadas11
 * @Date: 2025-09-10 19:29:49
 * @LastEditTime: 2025-09-10 19:29:57
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
string s,t;
void solve()
{
    cin>>n;
    cin>>s>>t;
    s=' '+s,t=' '+t;

    int ans=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]<t[i])
        {
            ans+=(n-i+1)*(cnt+1);
            cnt=0;
        }
        else if(s[i]==t[i]) cnt++;
        else cnt=0;
    }

    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}