/*
 * @Author: dsaDadas11
 * @Date: 2025-03-28 20:35:22
 * @LastEditTime: 2025-03-28 20:35:33
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int p,n,k;
int sum[N];
void solve()
{
    cin>>p>>n>>k;
    vector<int> a0,a1;
    int op,x;
    for(int i=1;i<=n;i++)
    {
        cin>>op>>x;
        if(op==0) a0.push_back(x);
        else a1.push_back(x);
    }
    sort(a0.begin(),a0.end());
    sort(a1.begin(),a1.end(),greater<>());
    int len0=a0.size(),len1=a1.size();
    sum[0]=0;
    for(int i=1;i<=len1;i++)
    {
        sum[i]=sum[i-1]+a1[i-1];
    }
    double ans=1e18,tmp=1.0;
    for(int i=0;i<=k;i++)
    {
        if(i>=1&&i-1<len0) tmp*=0.1*a0[i-1];
        ans=min(ans,(double)p*tmp-sum[min(k-i,len1)]);
    }
    ans=max(ans,0.0);
    cout<<fixed<<setprecision(2)<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}