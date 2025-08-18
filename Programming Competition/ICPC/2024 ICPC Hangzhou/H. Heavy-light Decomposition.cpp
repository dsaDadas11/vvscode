/*
 * @Author: dsaDadas11
 * @Date: 2025-07-29 16:25:09
 * @LastEditTime: 2025-07-29 16:33:37
 * @Description: go for it!
 */
/*
 解题思路：
 首先有两种情况不可能构成树：
 1.有两条及以上重链并且重链的长度全都相等，肉眼可见做不到
 2.有两条及以上重链长度为 maxn时且 maxn-minn<=1时不可，
 因为最短链最长的情况下就是放在头节点的下一个节点，那么 minn一定小于等于 maxn-2

 如何构造：
 1.当只有一条最长链时，其他链挂在这个链头即可
 2.如果有多条最长链，固定一个最长链，将最短链挂在链头下一个节点，将其他链挂在链头即可
 (最长链 + 最短链 > 最长链，因此最长链可以挂在固定的最长链的链头)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
struct op
{
    int l,r;
    int len;
    bool operator<(const op&a) const
    {
        return len<a.len;
    }
}a[N];
void solve()
{
    cin>>n>>k;
    int maxn=0,minn=1e9,cnt=0;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i].l>>a[i].r;
        a[i].len=a[i].r-a[i].l+1;  
    }
    sort(a+1,a+1+k);
    maxn=a[k].len,minn=a[1].len;
    for(int i=1;i<=k;i++)
    {
        if(a[i].len==maxn) cnt++;
    }

    if((maxn==minn&&cnt>=2)||(cnt>=2&&maxn-minn==1))
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<int> ans(n+1);
    int rt=a[k].l,sert=a[k].l+1;
    ans[rt]=0;
    if(cnt==1)
    {
        for(int i=a[k].l+1;i<=a[k].r;i++) ans[i]=i-1;
        for(int i=k-1;i>=1;i--)
        {
            ans[a[i].l]=rt;
            for(int j=a[i].l+1;j<=a[i].r;j++)
            {
                ans[j]=j-1;
            }
        }
    }
    else
    {
        for(int i=a[k].l+1;i<=a[k].r;i++) ans[i]=i-1;
        for(int i=k-1;i>=1;i--)
        {
            if(a[i].len!=minn)
            {
                ans[a[i].l]=rt;
                for(int j=a[i].l+1;j<=a[i].r;j++)
                {
                    ans[j]=j-1;
                }
            }
            else
            {
                ans[a[i].l]=sert;
                for(int j=a[i].l+1;j<=a[i].r;j++)
                {
                    ans[j]=j-1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}