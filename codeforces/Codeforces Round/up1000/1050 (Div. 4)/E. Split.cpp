/*
 * @Author: dsaDadas11
 * @Date: 2025-09-19 16:51:04
 * @LastEditTime: 2025-09-19 16:51:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
void solve()
{
    cin>>n>>k;
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(cnt[i]%k)
        {
            cout<<0<<endl;
            return;
        }
    }

    vector<int> tmp(n+1);
    int l=1,r=1;
    int ans=0;
    while(r<=n)
    {
        tmp[a[r]]++;
        while(tmp[a[r]]>cnt[a[r]]/k)
        {
            tmp[a[l]]--;
            l++;
        }
        ans+=r-l+1;
        r++;
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