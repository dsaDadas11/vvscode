/*
 * @Author: dsaDadas11
 * @Date: 2025-04-21 16:56:19
 * @LastEditTime: 2025-04-21 16:57:30
 * @Description: go for it!
 */
/*
 解题思路：
 算 K中每一个点可以对 I中哪些点产生贡献即可
 要注意枚举的是 K不是 O (调了一小时 bug才发现。。。)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,m,k,l;
int a[M][M];
int sum[M][M];
void solve()
{
    cin>>n>>m>>k>>l;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=l;j++)
        {
            int d=sum[n-k+i][m-l+j]-sum[n-k+i][j-1]-sum[i-1][m-l+j]+sum[i-1][j-1];
            ans+=abs(d);
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