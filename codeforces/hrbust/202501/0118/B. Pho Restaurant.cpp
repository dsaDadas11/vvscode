/*
 * @Author: dsaDadas11
 * @Date: 2025-01-18 21:06:41
 * @LastEditTime: 2025-01-18 21:06:51
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
string s[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    int ans=0;
    int res=1e18;
    bool flag0=0,flag1=0;
    for(int i=1;i<=n;i++)
    {
        int cnt1=0,cnt0=0;
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='0') cnt0++;
            else cnt1++;
        }
        if(cnt0>cnt1) flag0=1;
        else if(cnt0<cnt1) flag1=1;
        else flag0=1,flag1=1;
        ans+=min(cnt0,cnt1);
        res=min(res,abs(cnt0-cnt1));
    }
    if(flag0&&flag1||ans==0) return cout<<ans<<endl,void();
    cout<<ans+res<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}