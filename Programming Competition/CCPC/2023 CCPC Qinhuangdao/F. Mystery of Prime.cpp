/*
 * @Author: dsaDadas11
 * @Date: 2024-10-06 13:58:54
 * @LastEditTime: 2024-10-06 14:20:09
 * @Description: go for it!
 */
/*
 解题思路：
 这道题求将数组中的元素修改成满足相邻位相加为质数的最少修改次数，
 有个前提知识：
 1.1+1=2 为质数 (因此1的情况需要特判)
 2.偶+偶 或 奇+奇 一定不是质数
 3.偶+奇 一定能找到一个偶数或一个奇数使其和为质数

 这道题很难想到用dp求解，因为它与 i-1 和 i+1 都会影响，但是这里可以转移i-1的状态就行了，
 我们设dp[i][j] 表示 j=0 a[i]不变、j=1 a[i]变为1、j=2 a[i]变为偶数、j=3 a[i]变为>1的奇数
 状态转移方程有点复杂，
 1.j=0时 如果a[i-1]+a[i]为质数 那么 dp[i][0]=min dp[i-1][0]
         如果 1+a[i] 为质数 那么 dp[i][0]=min dp[i-1][1]
         如果 a[i]为偶数 那么 dp[i][0]=min dp[i-1][3]
         如果 a[i]为奇数 那么 dp[i][0]=min dp[i-1][2]
 2.j=1时(特判一下a[i]是否等于1)
    如果 a[i-1]+1 为质数 那么 dp[i][1]=min dp[i-1][0]+1(if a[i]==1)
    dp[i][1]=min dp[i-1][2]+1(if a[i]==1)
3.j=2时
    如果 a[i-1] 为奇数 那么 dp[i][2]=min dp[i-1][0]+1
    dp[i][2]=min dp[i-1][1]+1
    dp[i][2]=min dp[i-1][3]+1
3.j=3时
   如果 a[i-1] 为偶数 那么 dp[i][3]=min dp[i-1][0]+1
   dp[i][3]=dp[i-1][2]+1

 质数用质数筛判断一下就好
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,cnt;
int a[N],p[N];
bool b[N];
void pre()
{
    for(int i=2;i<N;i++)
    {
        if(!b[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&(ll)p[j]*i<N;j++)
        {
            b[p[j]*i]=1;//数组a存该数的最小质因子
            if(!i%p[j]) break;
        }
    }
}
// 0不变 1改为1 2改为偶数 3改为大于1的奇数
int dp[N][4];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0x3f,sizeof dp);
    dp[1][0]=0;
    dp[1][1]=dp[1][2]=dp[1][3]=1;
    if(a[1]==1) dp[1][1]=0;
    for(int i=2;i<=n;i++)
    {
        // 不变
        if(!b[a[i-1]+a[i]])
        {
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        }
        if(!b[a[i]+1])
        {
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        }
        if(a[i]%2==0)
        {
            dp[i][0]=min(dp[i][0],dp[i-1][3]);
        }
        else
        {
            dp[i][0]=min(dp[i][0],dp[i-1][2]);
        }

        // 改为1
        if(!b[a[i-1]+1])
        {
            dp[i][1]=min(dp[i][1],dp[i-1][0]+(int)(a[i]!=1));
        }
        dp[i][1]=min(dp[i][1],(min(dp[i-1][1],dp[i-1][2])+(int)(a[i]!=1)));

        // 改为偶数
        if(a[i-1]%2==1)
        {
            dp[i][2]=min(dp[i][2],dp[i-1][0]+1);
        }
        dp[i][2]=min(dp[i][2],(min(dp[i-1][3],dp[i-1][1])+1));

        // 改为奇数
        if(a[i-1]%2==0)
        {
            dp[i][3]=min(dp[i][3],dp[i-1][0]+1);
        }
        dp[i][3]=min(dp[i][3],dp[i-1][2]+1);
    }
    cout<<min({dp[n][0],dp[n][1],dp[n][2],dp[n][3]})<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}