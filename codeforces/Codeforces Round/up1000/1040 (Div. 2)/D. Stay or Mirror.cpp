/*
 * @Author: dsaDadas11
 * @Date: 2025-08-08 13:09:10
 * @LastEditTime: 2025-08-08 13:09:32
 * @Description: go for it!
 */
/*
 解题思路：
 直接判断变化前和变化后的贡献即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int sum1=0,sum2=0;
        for(int j=1;j<i;j++)
        {
            if(a[j]>a[i]) sum1++;
        }
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]>a[j]) sum1++;
        }

        for(int j=1;j<i;j++)
        {
            if(a[j]>2*n-a[i]) sum2++;
        }
        for(int j=i+1;j<=n;j++)
        {
            if(2*n-a[i]>a[j]) sum2++;
        }

        if(sum2<sum1) a[i]=2*n-a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]>a[i]) ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}