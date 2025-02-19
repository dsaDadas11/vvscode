/*
 * @Author: HuangCe
 * @Date: 2025-02-17 15:10:02
 * @LastEditTime: 2025-02-17 15:14:11
 * @Description: go for it!
 */
/*
 解题思路：
 没想到是一个非常简单的 dp，状态转移方程也非常简单
 正着求删除多少个元素很困难，那就反着求最长的接龙序列，ans=n-len
 设 dp[i]为以 i为数字最后一位的最长接龙序列长度
 我们只需要看数字的首位 x,末位 y, 那么首位 x就与先前的末位 x对应
 那么状态转移方程即为 dp[y]=max(dp[x]+1,dp[y])
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int dp[17];
void solve()
{
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        int x=s[0]-'0',y=s.back()-'0';
        dp[y]=max(dp[x]+1,dp[y]);
    }
    int len=0;
    for(int i=0;i<=9;i++)
    {
        len=max(len,dp[i]);
    }
    cout<<n-len<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}