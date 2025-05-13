/*
 * @Author: dsaDadas11
 * @Date: 2024-10-28 19:44:33
 * @LastEditTime: 2024-10-28 19:45:51
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/P3799
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n,ans;
int a[N];
unordered_map<int,int> mp;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=(ans*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return ans;
}
int niyuan(int x)
{
    return quickpow(x,mod-2);
}
void solve()
{
    cin>>n;
    int st=1e9,ed=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        st=min(st,a[i]);
        ed=max(ed,a[i]);
    }
    // i为要找的长度
    for(int i=st;i<=ed;i++)
    {
        if(mp[i]<2) continue;
        for(int j=st;j<=i/2;j++)
        {
            if(!mp[j]||!mp[i-j]) continue;
            if(j==i-j) ans+=(((mp[j]*(mp[j]-1))%mod)*niyuan(2LL)%mod)*((mp[i]*(mp[i]-1)%mod)*niyuan(2LL)%mod)%mod;
            else ans+=(mp[j]*mp[i-j]%mod)*((mp[i]*(mp[i]-1)%mod)*niyuan(2LL)%mod)%mod;
            ans%=mod;
        }
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