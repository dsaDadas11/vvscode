/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 16:55:51
 * @LastEditTime: 2025-06-07 16:57:03
 * @Description: go for it!
 */
/*
 解题思路：
 枚举 yl作为上边界，然后用滑动窗口滑左右边界，以 xr排序
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
struct op
{
    int xl,xr,yl,yr;
    bool operator<(const op&that) const
    {
        return xr<that.xr;
    }
}a[N];
int n,w,h;
int calc(int y)
{
    int cnt=0;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=1;i<=n;i++)
    {
        auto [xl,xr,yl,yr]=a[i];
        if(yr>y+h||yl<y) continue;
        pq.push(xl);
        while(!pq.empty()&&pq.top()<xr-w) pq.pop();
        cnt=max(cnt,(int)pq.size());
    }
    return cnt;
}
void solve()
{
    cin>>n>>w>>h;
    int x,y,r;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>r;
        a[i].xl=x-r,a[i].xr=x+r;
        a[i].yl=y-r,a[i].yr=y+r;
    }
    sort(a+1,a+1+n);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,calc(a[i].yl));
    }
    swap(w,h);
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,calc(a[i].yl));
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