/*
 * @Author: dsaDadas11
 * @Date: 2025-10-14 13:09:09
 * @LastEditTime: 2025-10-14 13:09:19
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e4+7;
constexpr int M=2e3+7;
int mu[N];
int a[N],p[N],cnt;
void init()
{
    mu[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&i*p[j]<N;j++)
        {
            a[p[j]*i]=1;
            if(i%p[j]==0) break;
            mu[i*p[j]]=-mu[i];
        }
    }
    // 前缀和
    for(int i=1;i<N;i++)
    {
        mu[i]+=mu[i-1];
    }
}
int n,m,k;
void solve()
{
    cin>>n>>m>>k;
    if(n>m) swap(n,m);
    n/=k,m/=k;
    int ans=0;
    for(int l=1,r;l<=n;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));
        ans+=(mu[r]-mu[l-1])*(n/l)*(m/l);
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