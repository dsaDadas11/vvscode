/*
 * @Author: dsaDadas11
 * @Date: 2024-10-05 12:21:22
 * @LastEditTime: 2024-10-05 19:21:33
 * @Description: go for it!
 */
/*
 解题思路：
 手玩一下可以发现往边上走就行
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N],b[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        ans+=abs(a[i]-a[i-1]);
    }
    for(int j=2;j<=m;j++)
    {
        ans+=abs(b[j]-b[j-1]);
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