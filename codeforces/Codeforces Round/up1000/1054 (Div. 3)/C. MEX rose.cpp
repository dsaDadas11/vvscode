/*
 * @Author: dsaDadas11
 * @Date: 2025-11-06 13:45:20
 * @LastEditTime: 2025-11-06 13:45:28
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
    vector<int> cnt(n+5,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    int ans=cnt[k];
    int res=0;
    for(int i=0;i<k;i++)
    {
        if(cnt[i]==0) res++;
    }
    cout<<ans+max(res-ans,0LL)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}