/*
 * @Author: dsaDadas11
 * @Date: 2025-06-11 19:01:18
 * @LastEditTime: 2025-06-11 19:01:25
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
int a[N],b[N];
bool check(int mid)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(mid-a[i]>b[i]) return 0;
        sum+=max(mid-a[i],0LL);
    }
    if(sum>m) return 0;
    return 1;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
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