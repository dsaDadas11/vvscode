/*
 * @Author: dsaDadas11
 * @Date: 2025-06-14 12:25:15
 * @LastEditTime: 2025-06-14 12:25:34
 * @Description: go for it!
 */
/*
 居然是线性 dp，没想到
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dp[2022];
int l,r;
void solve()
{
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=2021;i++)
    {
        for(int j=0;j<i;j++)
        {
            int l=j,r=i-j-1;
            dp[i]=min(dp[i],1+2*dp[l]+3*dp[r]+l*l*r);
        }
    }
    cout<<dp[2021]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}