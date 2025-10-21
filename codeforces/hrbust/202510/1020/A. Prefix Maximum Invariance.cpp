/*
 * @Author: dsaDadas11
 * @Date: 2025-10-20 21:32:31
 * @LastEditTime: 2025-10-20 21:36:25
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=4e5+7;
constexpr int M=2e3+7;
int n;
int a[N],b[N];
int f[N][20],lg[N];
void init()
{
    lg[1]=0;
    for(int i=2;i<N;i++)
    {
        lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
    }
}
int query(int l,int r)
{
    int k=lg[r-l+1];
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++) f[i][0]=a[i];
    for(int j=1;j<20;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    int ans=0;
    if(a[1]==b[1]) ans+=n;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=b[i]) continue;
        int l=1,r=i-1;
        int res=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(query(mid,i-1)>=a[i])
            {
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        ans+=(i-res)*(n-i+1);
    }

    for(int i=2;i<=n;i++)
    {
        int mx=max(a[i],b[i]);
        int l=1,r=i-1;
        int res=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(query(mid,i-1)>=mx)
            {
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        ans+=res*(n-i+1);
    }

    cout<<ans<<endl;

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}