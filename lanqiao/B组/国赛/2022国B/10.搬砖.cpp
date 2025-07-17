/*
 * @Author: dsaDadas11
 * @Date: 2025-06-13 18:30:20
 * @LastEditTime: 2025-06-13 18:36:02
 * @Description: go for it!
 */
/*
 贪心 + dp
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e4+7;
constexpr int M=2e3+7;
int n;
struct op
{
    int w,v;
    bool operator<(const op&a) const
    {
        return w+v<a.w+a.v;
    }
} p[N];

int dp[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].w>>p[i].v;
    }
    sort(p+1,p+1+n);

    for(int i=1;i<=n;i++)
    {
        for(int j=N-1;j>=p[i].w;j--)
        {
            if(j-p[i].w<=p[i].v)
            dp[j]=max(dp[j],dp[j-p[i].w]+p[i].v);
        }
    }

    int ans=0;
    for(int i=0;i<N;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}