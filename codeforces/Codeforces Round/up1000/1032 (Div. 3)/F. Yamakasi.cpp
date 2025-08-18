/*
 * @Author: dsaDadas11
 * @Date: 2025-08-01 15:46:05
 * @LastEditTime: 2025-08-01 15:46:10
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,s,x;
int a[N];
int sum[N];
void solve()
{
    cin>>n>>s>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    map<int,int> cnt;
    int l=1,ans=0;
    for(int r=1;r<=n;r++)
    {
        if(a[r]>x)
        {
            cnt.clear();
            l=r+1;
        }
        else if(a[r]==x)
        {
            while(l<=r)
            {
                cnt[sum[l-1]]++;
                l++;
            }
        }
        ans+=cnt[sum[r]-s];
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}