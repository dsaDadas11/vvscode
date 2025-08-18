/*
 * @Author: dsaDadas11
 * @Date: 2025-07-28 16:21:10
 * @LastEditTime: 2025-07-28 16:21:16
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct op
{
    int l,r,real;
    bool operator<(const op&that) const
    {
        return l<that.l;
    }
}a[N];
int n,k;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r>>a[i].real;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i].l>k||a[i].r<k||a[i].real<k) continue;
        k=a[i].real;
    }
    cout<<k<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}