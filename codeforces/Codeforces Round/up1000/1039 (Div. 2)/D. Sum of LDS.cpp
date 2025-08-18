/*
 * @Author: dsaDadas11
 * @Date: 2025-08-02 11:41:14
 * @LastEditTime: 2025-08-02 11:41:20
 * @Description: go for it!
 */
/*
 解题思路：
 我们看 p[i] < p[i+1]的情况
 p[i+2] < max(p[i],p[i+1]) 即 p[i+2] < p[i+1]
 并且 p[i-1]=max(p[i-1],p[i]) > p[i+1]
 因此 p[i-1] > p[i+1] > p[i+2] 里面只少了 p[i]的贡献，并且可以发现整个数组都是递减的，除了 p[i] < p[i+1]的情况
 包含 p[i] < p[i+1]的区间个数为 i*(n-i)，用整体减去即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
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
        ans+=i*(n-i+1);
    }

    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i+1]) ans-=i*(n-i);
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