/*
 * @Author: dsaDadas11
 * @Date: 2025-11-12 10:50:45
 * @LastEditTime: 2025-11-12 10:50:54
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
int a[107];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    vector<int> cnt(n+5,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[a[i]]) continue;
        cnt[a[i]]++;
        ans++;
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