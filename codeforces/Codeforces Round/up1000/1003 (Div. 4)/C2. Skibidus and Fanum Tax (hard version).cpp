/*
 * @Author: HuangCe
 * @Date: 2025-02-11 19:02:07
 * @LastEditTime: 2025-02-11 19:07:44
 * @Description: go for it!
 */
/*
 解题思路：
 这是寒假康复训练后的第一次题解，一开始是不会做的，但是看到了一篇博客写的一句话直接悟到。
 贪心，对于 n这个位置来说，我们将 an变为更大，即 max(an,bi-an)，
 然后 最大化 n-1，以此类推，这样子对非递减序列一定是最优的
 最后用再判断是否为递增序列即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e18;
int n,m;
int a[N],b[N];
bool check(int idx,int mid)
{
    if(b[mid]-a[idx]<=a[idx+1]) return 1;
    else return 0;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(b+1,b+1+m);
    a[n+1]=inf;
    for(int i=n;i>=1;i--)
    {
        int maxn=0;
        int l=1,r=m;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(check(i,mid)) l=mid;
            else r=mid-1;
        }
        if(a[i]<=a[i+1])
        {
            if(b[l]-a[i]<=a[i+1])
            {
                a[i]=max(a[i],b[l]-a[i]);
            }
        }
        else if(b[l]-a[i]<=a[i+1])
        {
            a[i]=b[l]-a[i];
        }
    }
    if(is_sorted(a+1,a+1+n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}