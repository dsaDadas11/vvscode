/*
 * @Author: dsaDadas11
 * @Date: 2025-08-22 19:32:32
 * @LastEditTime: 2025-08-22 19:32:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,s;
int h=1,t=0;
int q[N];
int c[N],tim[N],f[N];
int dy(int j,int k)
{
    return f[j]-f[k];
}
int dx(int j,int k)
{
    return c[j]-c[k];
}
int bs(int i) // 二分查找
{
    if(h==t) return q[h];
    int l=h,r=t;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(dy(q[mid],q[mid-1])<=dx(q[mid],q[mid-1])*(tim[i]+s))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    return q[ans];
}
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>tim[i]>>c[i];
        tim[i]+=tim[i-1],c[i]+=c[i-1];
    }

    for(int i=1;i<=n;i++)
    {
        while(h<t&&dy(i-1,q[t])*dx(q[t],q[t-1])<=dx(i-1,q[t])*dy(q[t],q[t-1])) t--; // 要保证 k的正负性
        q[++t]=i-1;
        int j=bs(i);
        f[i]=f[j]+tim[i]*(c[i]-c[j])+s*(c[n]-c[j]);
    }
    cout<<f[n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}