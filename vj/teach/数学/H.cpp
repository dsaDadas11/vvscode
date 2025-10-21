/*
 * @Author: dsaDadas11
 * @Date: 2025-10-15 21:11:09
 * @LastEditTime: 2025-10-15 21:11:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int mu[N],sum[N];
int a[N],p[N],cnt;
void init()
{
    mu[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
        {
            a[p[j]*i]=1;
            if(i%p[j]==0) break;
            mu[i*p[j]]=-mu[i];
        }
    }

    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            sum[j]+=mu[j/i]*i;
        }
    }
    for(int i=1;i<N;i++)
    {
        sum[i]+=sum[i-1];
    }
}
int n;
void solve()
{
    cin>>n;
    int ans=0;
    for(int l=1,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        ans+=(sum[r]-sum[l-1])*(n/l)*(n/l);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}