/*
 * @Author: dsaDadas11
 * @Date: 2025-08-23 14:10:06
 * @LastEditTime: 2025-08-23 14:10:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
pair<int,int> p[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);

    int l=1,r=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        auto [x,y]=p[i];
        if(r<x)
        {
            ans+=r-l+1;
            l=x,r=y;
        }
        else
        {
            l=min(l,x);
            r=max(r,y);
        }
    }
    ans+=r-l+1;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}