/*
 * @Author: dsaDadas11
 * @Date: 2025-08-02 20:07:46
 * @LastEditTime: 2025-08-02 20:08:29
 * @Description: go for it!
 */
/*
 解题思路：
 不懂为何用找最小的就能 ac，找最大的反而找出来的 l更小，不对
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
bool check(int x)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x) sum+=a[i]-x+1;
    }
    if(sum>=k) return 1;
    return 0;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    int l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    int ans=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<l) continue;
        ans+=(a[i]+l)*(a[i]-l+1)/2;
        sum+=a[i]-l+1;
        a[i]=l-1;
    }
    while(sum<k)
    {
        l--;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<l) continue;
            ans+=a[i];
            sum++;
            a[i]=l-1;
            if(sum>=k) break;
        }
        if(sum>=k) break;
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