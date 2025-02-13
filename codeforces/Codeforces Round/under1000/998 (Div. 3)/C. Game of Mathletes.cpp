/*
 * @Author: dsaDadas11
 * @Date: 2025-01-20 00:21:43
 * @LastEditTime: 2025-01-20 00:21:56
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n, k;
int a[N];
void solve()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    map<int, int> mp;
    for (int i=1;i<=n;i++) {
        mp[a[i]]++;
    }
    int ans=0;
    for (int i = 1; i <= n; i++)
    {
        if(i>k-i) continue;
        if(i==k-i)
        {
            ans+=mp[i]/2;
        }
        else
        {
            ans+=min(mp[i],mp[k-i]);
        }
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