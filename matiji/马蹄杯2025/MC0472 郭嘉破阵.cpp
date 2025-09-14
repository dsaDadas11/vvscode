/*
 * @Author: dsaDadas11
 * @Date: 2025-08-23 15:00:59
 * @LastEditTime: 2025-08-23 15:02:34
 * @Description: go for it!
 */
/*
 二进制拆位，然后算每一位会在哪些区间异或为 1时产生贡献，
 我们要记录前缀 0和前缀 1的数量，推一下式子就知道怎么求了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n;
int a[N],b[N];
int xr[N],sum[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        xr[i]=xr[i-1]^a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        sum[i]=(sum[i-1]+b[i])%mod;
    }

    int ans=0;
    for(int j=0;j<=30;j++)
    {
        int cnt0=1,cnt1=0;
        int res0=0,res1=0;
        for(int i=1;i<=n;i++)
        {
            if((xr[i]>>j)&1)
            {
                ans+=(1LL<<j)*(cnt0*sum[i]%mod-res0);
                res1+=sum[i],cnt1++;
            }
            else
            {
                ans+=(1LL<<j)*(cnt1*sum[i]%mod-res1);
                res0+=sum[i],cnt0++;
            }
            res1%=mod,res0%=mod;
            ans=(ans%mod+mod)%mod;
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