/*
 * @Author: dsaDadas11
 * @Date: 2025-04-07 19:37:20
 * @LastEditTime: 2025-04-07 19:47:29
 * @Description: go for it!
 */
/*
 解题思路：
 这题也能枚举上下界，然后用双指针枚举每个上下界中 [1,m]的答案，O(n^3)实现
 不过二分的 O(n^3logn)也差不多捏
 看大家都是用双指针做，我发个二分做法吧 枚举每个 (i,j)，根据这个点往下遍历 k，
 因为数组值大于等于0，因此前缀和具有单调性，
 再用二分找出 (i,j)到 (k,l)的可行的 l，每个 j-l+1即为答案（需要特判 l是否可行）
 时间复杂度 O(n^3logn) n很小可以媲美 O(n^3)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=5e2+7;
int n,m,k;
int a[M][M];
int sum[M][M];
bool check(int x1,int y1,int x2,int y2)
{
    if(sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]<=k) return 1;
    return 0;
}
void solve()
{
    cin>>n>>m>>k;
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
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=i;k<=n;k++)
            {
                int l=j,r=m;
                while(l<r)
                {
                    int mid=(l+r+1)>>1;
                    if(check(i,j,k,mid)) l=mid;
                    else r=mid-1;
                }
                if(check(i,j,k,l)) ans+=l-j+1;
                else ans+=l-j;
                
            }
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