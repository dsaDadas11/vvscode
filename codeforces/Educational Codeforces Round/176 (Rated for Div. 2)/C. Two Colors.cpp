/*
 * @Author: dsaDadas11
 * @Date: 2025-04-20 10:51:29
 * @LastEditTime: 2025-04-20 10:55:12
 * @Description: go for it!
 */
/*
 解题思路：
 一开始的思路：从 1-n枚举每个 ai，用二分找 aj>=n-ai，但是这样时间复杂度就为 n*m了
 后来想可以直接枚举 1-n (喷漆数量)，然后二分找符合条件的 i和 n-i
 然后除去大于 max(i,n-i)的重复选择的点即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int x=m-(lower_bound(a+1,a+1+m,i)-a-1);
        int y=m-(lower_bound(a+1,a+1+m,n-i)-a-1);
        int z=m-(lower_bound(a+1,a+1+m,max(i,n-i))-a-1);
        ans+=x*y-z;
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