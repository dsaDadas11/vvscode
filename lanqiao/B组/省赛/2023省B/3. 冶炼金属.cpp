/*
 * @Author: HuangCe
 * @Date: 2025-02-17 14:27:25
 * @LastEditTime: 2025-02-17 14:27:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
int n;
int a[N],b[N];
bool check1(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(b[i]<a[i]/x) return 1;
    }
    return 0;
}
bool check2(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(b[i]>a[i]/x) return 0;
    }
    return 1;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int ansl,ansr;
    int l=1,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check1(mid)) l=mid+1;
        else r=mid;
    }
    ansl=l;

    l=1,r=1e9;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check2(mid)) l=mid;
        else r=mid-1;
    }
    ansr=l;
    
    cout<<ansl<<' '<<ansr<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}