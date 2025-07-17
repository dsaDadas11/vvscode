/*
 * @Author: dsaDadas11
 * @Date: 2025-06-14 12:48:01
 * @LastEditTime: 2025-06-14 12:48:08
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e6+7;
constexpr int M=2e3+7;
int d[N];
int sum[N];
void init()
{
    for(int i=1;i<N;i++)
    {
        d[i]=i*(i+1)/2;
    }
    for(int i=1;i<N;i++)
    {
        sum[i]=sum[i-1]+d[i];
    }
}
int query(int x)
{
    int l=0,r=N;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(mid*(mid+1)>2*x) r=mid-1;
        else l=mid;
    }
    int dn1=x-l*(l+1)/2;
    int sum1=sum[l]+dn1*(dn1+1)/2;
    return sum1;
}
void solve()
{
    int l,r;
    cin>>l>>r;
    cout<<query(r)-query(l-1)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}