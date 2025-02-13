/*
 * @Author: dsaDadas11
 * @Date: 2025-01-20 00:21:14
 * @LastEditTime: 2025-01-20 10:17:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
void solve()
{
    cin>>n>>m;
    vector<vector<int> > v(n+7,vector<int>(m+7));
    vector<pair<int,int> > order;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin()+1,v[i].begin()+1+m);
        order.push_back({v[i][1],i});
    }
    sort(order.begin(),order.end());
    set<int> check;
    for(int j=1;j<=m;j++)
    {
        for(auto [x,y]:order)
        {
            if(check.lower_bound(v[y][j])!=check.end())
            {
                cout<<"-1"<<endl;
                return;
            }
            check.insert(v[y][j]);
        }
    }
    if(check.size()!=n*m)
    {
        cout<<"-1"<<endl;
        return;
    }
    for(auto [x,y]:order)
    {
        cout<<y<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}