/*
 * @Author: dsaDadas11
 * @Date: 2025-09-16 16:36:53
 * @LastEditTime: 2025-09-16 16:37:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=100003;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int m,n;
void solve()
{
    cin>>m>>n;
    int ans=quickpow(m,n)-m*quickpow(m-1,n-1)%mod;
    cout<<(ans+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}