/*
 * @Author: dsaDadas11
 * @Date: 2025-08-02 16:39:18
 * @LastEditTime: 2025-08-02 16:39:26
 * @Description: go for it!
 */
/*
 无后效性 dp
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
double k,c,w;
int op[N],a[N];
double dp[N];
void solve()
{
    cin>>n>>k>>c>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i]>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(op[i]==1) dp[i]=max(dp[i+1],a[i]+dp[i+1]*(1-0.01*k));
        else dp[i]=max(dp[i+1],-a[i]+dp[i+1]*(1+0.01*c));
    }
    cout<<fixed<<setprecision(2)<<dp[1]*w<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}