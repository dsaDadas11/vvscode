/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 13:29:41
 * @LastEditTime: 2025-06-07 13:29:50
 * @Description: go for it!
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
bool check(int mid)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int d=a[i]-a[i-1];
        if(d<=mid) continue; // a[i]可能等于a[i-1]...得特判，不然 sum-1了
        //等价于 if(a[i]==a[i-1]) continue;
        sum+=((d+mid-1)/mid)-1;
    }
    if(sum<=m) return 0;
    return 1;
}
void solve()
{
    cin>>n>>m;
    m++;
    a[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1e8;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}