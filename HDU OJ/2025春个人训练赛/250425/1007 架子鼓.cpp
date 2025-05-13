/*
 * @Author: dsaDadas11
 * @Date: 2025-04-25 18:50:34
 * @LastEditTime: 2025-04-25 18:50:51
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n1,n2;
pair<int,int> p[N],q[N];
void solve()
{
    cin>>n1>>n2;
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n1;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    for(int i=1;i<=n2;i++)
    {
        cin>>q[i].first>>q[i].second;
    }
    int fenz=p[1].first,fenm=p[1].second;
    mp[{fenz,fenm}]++;
    for(int i=2;i<n1;i++)
    {
        int tmp1=fenz*p[i].second+p[i].first*fenm;
        int tmp2=fenm*p[i].second;
        fenz=tmp1,fenm=tmp2;
        int gg=gcd(fenz,fenm);
        fenz/=gg;
        fenm/=gg;
        mp[{fenz,fenm}]++;
    }
    int ans=1;
    fenz=q[1].first,fenm=q[1].second;
    ans+=mp[{fenz,fenm}];
    for(int i=2;i<n2;i++)
    {
        int tmp1=fenz*q[i].second+q[i].first*fenm;
        int tmp2=fenm*q[i].second;
        fenz=tmp1,fenm=tmp2;
        int gg=gcd(fenz,fenm);
        fenz/=gg;
        fenm/=gg;
        ans+=mp[{fenz,fenm}];
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}