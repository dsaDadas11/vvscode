/*
 * @Author: dsaDadas11
 * @Date: 2025-08-09 16:21:26
 * @LastEditTime: 2025-08-09 16:21:35
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b,x,y;
void solve()
{
    cin>>a>>b>>x>>y;
    if(a>b&&(a^1)!=b)
    {
        cout<<"-1"<<endl;
        return;
    }

    if(a>b&&(a^1)==b)
    {
        cout<<y<<endl;
        return;
    }

    if(a==b)
    {
        cout<<0<<endl;
        return;
    }

    int ans=0;
    if(x<=y) ans+=(b-a)*x;
    else
    {
        while(a!=b)
        {
            if((a^1)>a) ans+=y;
            else ans+=x;
            a++;
        }
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