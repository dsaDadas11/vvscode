/*
 * @Author: dsaDadas11
 * @Date: 2025-03-16 21:07:58
 * @LastEditTime: 2025-03-16 21:08:15
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
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
        if(p[i].first>p[i].second) swap(p[i].first,p[i].second);
    }
    sort(p+1,p+1+n);
    set<int> r;
    for(int i=1;i<=n;i++)
    {
        if(r.lower_bound(p[i].first)!=r.lower_bound(p[i].second))
        {
            cout<<"Yes"<<endl;
            return;
        }
        r.insert(p[i].second);
    }
    cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}