/*
 * @Author: dsaDadas11
 * @Date: 2025-11-01 16:09:10
 * @LastEditTime: 2025-11-01 16:09:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,l;
void solve()
{
    cin>>n>>m;
    vector<vector<int> > a(n);
    vector<int> cnt(m+5);
    for(int i=0;i<n;i++)
    {
        cin>>l;
        a[i].resize(l);
        for(int j=0;j<l;j++)
        {
            cin>>a[i][j];
            cnt[a[i][j]]++;
        }
    }

    for(int i=1;i<=m;i++)
    {
        if(cnt[i]==0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    int ans=1;
    for(int i=0;i<n;i++)
    {
        bool ok=1;
        for(auto x:a[i])
        {
            cnt[x]--;
            if(cnt[x]<=0) ok=0;
        }

        if(ok) ans++;

        for(auto x:a[i])
        {
            cnt[x]++;
        }
    }

    if(ans>=3) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}