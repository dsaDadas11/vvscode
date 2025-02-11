/*
 * @Author: dsaDadas11
 * @Date: 2025-01-14 17:34:05
 * @LastEditTime: 2025-01-14 17:34:15
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
void solve()
{
    cin>>n>>m>>k;
    map<string,vector<pair<int,int> > > mp;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            string s;
            for(int g=1;g<=k;g++)
            {
                cin>>c;
                s.push_back(c);
            }
            mp[s].push_back({i,j});
        }
    }
    for(auto [x,y]:mp)
    {
        if(y.size()==1)
        {
            cout<<y[0].first<<' '<<y[0].second<<endl;
            break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}