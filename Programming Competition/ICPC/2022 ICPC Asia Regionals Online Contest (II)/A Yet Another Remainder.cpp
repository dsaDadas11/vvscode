/*
 * @Author: dsaDadas11
 * @Date: 2025-09-11 15:39:08
 * @LastEditTime: 2025-09-11 15:39:25
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
int b[107][107];
int q,p;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%p;
        x=x*x%p;
        y>>=1;
    }
    return ans;
}
void solve()
{
    cin>>n;
    int len=min(n,100LL);
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>b[i][j];
        }
    }

    cin>>q;
    while(q--)
    {
        cin>>p;
        if(n<=100)
        {
            int base=1;
            int ans=0;
            for(int i=n;i>=1;i--)
            {
                ans+=b[n][i]*base%p;
                ans%=p;
                base=base*10%p;
            }
            cout<<ans<<endl;
        }
        else
        {
            int base=quickpow(10,n-1),inv=quickpow(10,p-2);
            int ans=0;
            for(int i=1;i<=p-1;i++)
            {
                ans+=b[p-1][i]*base%p;
                ans%=p;
                base=base*inv%p;
            }
            cout<<ans<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}