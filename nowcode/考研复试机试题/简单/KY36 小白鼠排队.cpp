/*
 * @Author: dsaDadas11
 * @Date: 2026-01-29 17:10:17
 * @LastEditTime: 2026-01-29 17:10:23
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
void solve()
{
    vector<pair<int,string> > p(n);
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(p.begin(),p.end(),greater<>());
    for(int i=0;i<n;i++)
    {
        cout<<p[i].second<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>n){solve();}
    return 0;
}