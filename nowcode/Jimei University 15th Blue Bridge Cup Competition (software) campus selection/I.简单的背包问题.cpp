/*
 * @Author: dsaDadas11
 * @Date: 2024-01-20 20:32:29
 * @LastEditTime: 2024-01-20 20:32:34
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e4+7;
const int M=2e3+7;
const int inf=1e18;
int dp[N];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin>>n;
    fill(dp+1,dp+N,inf);
    for(int i=1;i<=n;i++)
    {
        int  w,v; cin>>w>>v;
        for(int j=N-1;j>=v;j--)
        {
            dp[j]=min(dp[j],dp[j-v]+w);
        }
    }
    for(int i=N-2;i>=0;i--)
        dp[i]=min(dp[i],dp[i+1]);
    int q; cin>>q;
    while(q--)
    {
        int W; cin>>W;
        int ans=upper_bound(dp,dp+N,W)-dp-1;
        cout<<ans<<endl;
    }
	return 0;
}