/*
 * @Author: dsaDadas11
 * @Date: 2025-06-12 18:28:25
 * @LastEditTime: 2025-06-12 18:29:33
 * @Description: go for it!
 */
/*
 解题思路：
 分组背包，只能选 i-k之前或 i+k之后的，最大体积为 m
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int month[17]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day[13][33];
int n,m,k;
vector<int> v[367];
int dp[367][5007];
void solve()
{
    for(int i=1;i<=12;i++) month[i]+=month[i-1];

    cin>>n>>m>>k;
    int a,b,c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        v[month[a-1]+b].push_back(c);
    }

    int ans=0;
    for(int i=1;i<=365;i++)
    {
        int pre=max(0LL,i-k);
        for(int w=1;w<=m;w++)
        {
            dp[i][w]=dp[i-1][w];
            for(auto val:v[i])
            {
                if(w>=val)
                dp[i][w]=max(dp[i][w],dp[pre][w-val]+val);
            }
            ans=max(ans,dp[i][w]);
        }
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