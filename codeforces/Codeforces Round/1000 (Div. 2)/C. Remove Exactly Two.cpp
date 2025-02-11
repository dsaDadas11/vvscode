/*
 * @Author: dsaDadas11
 * @Date: 2025-01-22 21:38:59
 * @LastEditTime: 2025-01-23 09:47:04
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
int d[N];
pair<int,int> p[N];
void solve()
{
    cin>>n;
    for(int i=0;i<=n+5;i++) d[i]=0;
    map<pair<int,int>,int> mp;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[i]={u,v};
        mp[{u,v}]=1,mp[{v,u}]=1;
        d[u]++,d[v]++;
    }
    if(n==2)
    {
        cout<<"0"<<endl;
        return;
    }
    vector<pair<int,int> > v;
    for(int i=1;i<=n;i++)
    {
        v.emplace_back(d[i],i);
    }
    sort(v.begin(),v.end(),greater<>());
    int sum1=0,sum2=0;
    for(int i=1;i<n;i++)
    {
        auto [u,v]=p[i];
        sum1=max(sum1,d[u]+d[v]-2);
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(!mp[{v[i].second,v[j].second}])
            {
                sum2=max(sum2,v[i].first+v[j].first-1);
                break;
            }
        }
    }
    cout<<max(sum1,sum2)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}