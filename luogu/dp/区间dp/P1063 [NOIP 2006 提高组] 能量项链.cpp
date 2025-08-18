/*
 * @Author: dsaDadas11
 * @Date: 2025-08-13 15:01:32
 * @LastEditTime: 2025-08-13 15:01:44
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
int dp[207][207];
int a[207];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    n*=2;

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[j+1]*a[k+1]);
            }
        }
    }

    int st=1,ed=n/2;
    int ans=0;
    while(ed<=n)
    {
        ans=max(ans,dp[st][ed]);
        st++,ed++;
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