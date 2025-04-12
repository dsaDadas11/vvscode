/*
 * @Author: dsaDadas11
 * @Date: 2025-04-03 14:50:17
 * @LastEditTime: 2025-04-03 14:50:27
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
    cin>>n;
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        s=to_string(i);
        reverse(s.begin(),s.end());
        bool ok1=0,ok2=0;
        for(int j=0;j<s.size();j++)
        {
            if(j&1)
            {
                if((s[j]-'0')&1) ok1=1;
            }
            else
            {
                if((s[j]-'0')%2==0) ok2=1;
            }
        }
        if(ok1||ok2) ans--;
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