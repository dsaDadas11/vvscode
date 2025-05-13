/*
 * @Author: dsaDadas11
 * @Date: 2025-05-02 14:36:29
 * @LastEditTime: 2025-05-02 14:36:56
 * @Description: go for it!
 */
/*
 相加的时候就得取模，不然爆 long long
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return ans;
}
int ni(int x)
{
    return quickpow(x,mod-2);
}
int n,x;
void solve()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        sum+=x;
        sum%=mod;
    }
    cout<<sum*ni(n)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}