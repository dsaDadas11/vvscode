/*
 * @Author: dsaDadas11
 * @Date: 2025-09-22 19:56:34
 * @LastEditTime: 2025-09-22 19:56:48
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int p[N];
set<int> se;
int get(int x)
{
    auto pos=se.upper_bound(x);
    if(pos==se.end()) pos=se.begin();
    return *pos;
}
void solve()
{
    cin>>n;
    se.clear();
    vector<int> cnt(n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        cnt[p[i]]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==0) se.insert(i);
    }

    for(int i=1;i<=n;i++)
    {
        if(p[i]) continue;
        p[i]=*se.rbegin();
        se.erase(*se.rbegin());
    }

    int l=1,r=n;
    while(l<=n&&l==p[l]) l++;
    while(r>=1&&r==p[r]) r--;
    cout<<max(0LL,r-l+1)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}