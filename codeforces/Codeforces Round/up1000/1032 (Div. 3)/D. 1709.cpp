/*
 * @Author: dsaDadas11
 * @Date: 2025-08-01 14:45:59
 * @LastEditTime: 2025-08-01 14:46:07
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
int a[47],b[47];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    vector<pair<int,int> > ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[j+1]<a[j])
            {
                swap(a[j+1],a[j]);
                ans.push_back({1,j});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(b[j+1]<b[j])
            {
                swap(b[j+1],b[j]);
                ans.push_back({2,j});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]>b[i])
        {
            swap(a[i],b[i]);
            ans.push_back({3,i});
        }
    }
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}