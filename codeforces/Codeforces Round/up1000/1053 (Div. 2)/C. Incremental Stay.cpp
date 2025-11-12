/*
 * @Author: dsaDadas11
 * @Date: 2025-11-02 22:02:39
 * @LastEditTime: 2025-11-02 22:02:48
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
int a[N];
int sum1[N],sum2[N],sum3[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
        sum1[i]=sum1[i-1]+a[i];
        sum2[i]=sum2[i-1]+((i&1)?a[i]:-a[i]);
        sum3[i]=sum3[i-1]+((i&1)?-a[i]:a[i]);
    }

    for(int k=1;k<=n;k++)
    {
        int ans=sum1[2*n]-sum1[2*n-k]-sum1[k];
        if(k&1) ans+=sum3[2*n-k]-sum3[k];
        else ans+=sum2[2*n-k]-sum2[k];
        cout<<ans<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}