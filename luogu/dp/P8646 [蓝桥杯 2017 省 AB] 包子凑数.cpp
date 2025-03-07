/*
 * @Author: dsaDadas11
 * @Date: 2025-03-03 20:31:27
 * @LastEditTime: 2025-03-03 20:38:26
 * @Description: go for it!
 */
/*
 解题思路：
 裴蜀定理 + dp
 首先对于方程 ax + by = d, 令 g=gcd(a,b)
 若 g=1，那么肯定凑不出的数是有限的，因为 1能整除任何 d
 否则凑不出的数是无限的，因为肯定能找到不能被 g整除的 d
 并且有定理：如果 a,b均是正整数且互质，那么由 ax+by,x≥0,y≥0不能凑出的最大数是 (a−1)(b−1)−1（这是定理，证明很难，记住定理即可）。
 因此我们能用完全背包找能凑出的数，背包容量 v <= max(ai)*max(ai)
 并且我发现完全背包先枚举 n还是先枚举 v都可以
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[107],dp[10007];
void solve()
{
    cin>>n;
    int g=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(g==0) g=a[i];
        else g=gcd(g,a[i]);
        mx=max(mx,a[i]);
    }
    if(g!=1) return cout<<"INF"<<endl,void();
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i];j<=mx*mx;j++)
        {
            if(!dp[j-a[i]]) continue;
            dp[j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<=mx*mx;i++)
    {
        if(!dp[i]) ans++;
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