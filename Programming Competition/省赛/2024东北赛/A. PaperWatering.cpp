/*
 * @Author: dsaDadas11
 * @Date: 2025-05-15 17:52:06
 * @LastEditTime: 2025-05-15 17:52:15
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,k;
void solve()
{
    cin>>x>>k;
    if(x==1)
    {
        cout<<1<<endl;
        return;
    }
    int ans=k+1;
    int tar=x;
    while(x!=1&&k)
    {
        tar=x;
        x=sqrt(x);
        k--;
        ans++;
        if(x==1||k==0) break;
        if(x*x!=tar) ans+=k;
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