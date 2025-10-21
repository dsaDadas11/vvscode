/*
 * @Author: dsaDadas11
 * @Date: 2025-10-13 15:43:30
 * @LastEditTime: 2025-10-13 16:12:09
 * @Description: go for it!
 */
// URL：https://codeforces.com/problemset/problem/757/E
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=1e6+3;
constexpr int mod=1e9+7;
ll f[N][23]; // r  次方
void init()
{
    f[0][0]=1;
    for(int i=1;i<=20;i++)
    {
        f[0][i]=f[0][i-1]*2%mod;
    }
    f[1][1]=1;
    for(int i=1;i<=20;i++)
    {
        f[1][i]=1+2*i;
    }

    for(int i=2;i<N;i++)
    {
        f[i][0]=1;
        for(int j=1;j<=20;j++)
        {
            f[i][j]=(f[i][j-1]+f[i-1][j])%mod;
        }
    }
}
int r,n;
void solve()
{
    cin>>r>>n;
    vector<int> d;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i) continue;
        int cnt=0;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        d.push_back(cnt);
    }
    if(n>1) d.push_back(1);
    
    ll ans=1;
    if(r==0) return cout<<f[r][d.size()]<<endl,void();
    for(auto j:d)
    {
        ans=ans*f[r][j]%mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}