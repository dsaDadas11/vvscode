/*
 * @Author: dsaDadas11
 * @Date: 2025-08-21 15:40:53
 * @LastEditTime: 2025-08-21 15:45:36
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,tim;
int a[N];
int f[N];
int q[N];
bool check(int k)
{
    k++; // k段不能选，也就是 k+1段中选 1个
    int h=1,t=0;
    q[0]=q[1]=0;
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&f[q[t]]>=f[i-1]) t--;
        q[++t]=i-1;
        if(i-q[h]>k) h++;
        f[i]=a[i]+f[q[h]];
    }
    int ans=1e9;
    for(int i=n-k+1;i<=n;i++) ans=min(ans,f[i]);
    return ans<=tim;
}
void solve()
{
    cin>>n>>tim;
    for(int i=1;i<=n;i++) cin>>a[i];

    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    while(!check(l)&&l>0) l--;
    cout<<l<<endl;
    //cout<<r<<endl; 这也是正确答案

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

/*
while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
*/