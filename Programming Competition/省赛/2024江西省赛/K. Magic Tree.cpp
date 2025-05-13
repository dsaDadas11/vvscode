/*
 * @Author: dsaDadas11
 * @Date: 2025-04-21 16:05:09
 * @LastEditTime: 2025-04-21 16:05:52
 * @Description: go for it!
 */
/*
 解题思路：
 手玩出来应该是 2^(n-1)次方，但是没有严谨证明，然后写了记忆化神秘 dfs错了
 结果把手玩的结论交一发，居然是对的
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
void solve()
{
    cin>>n;
    int ans=1;
    for(int i=1;i<n;i++)
    {
        ans*=2;
        ans%=mod;
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