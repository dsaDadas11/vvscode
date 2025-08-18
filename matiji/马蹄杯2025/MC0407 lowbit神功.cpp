/*
 * @Author: dsaDadas11
 * @Date: 2025-08-02 19:21:07
 * @LastEditTime: 2025-08-02 19:21:41
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n,q,x;
int sum[37];
int lowbit(int x)
{
    return x&(-x);
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int j=0;j<31;j++)
        {
            sum[j]=(sum[j]+x%mod)%mod;
            x+=lowbit(x);
        }
    }
    int cnt=0;
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            if(cnt<30) cnt++;
            else
            {
                sum[cnt]<<=1LL;
                sum[cnt]%=mod;
            }
        }
        else
        {
            cout<<sum[cnt]<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}