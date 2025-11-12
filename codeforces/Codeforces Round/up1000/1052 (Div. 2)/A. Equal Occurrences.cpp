/*
 * @Author: dsaDadas11
 * @Date: 2025-11-01 15:30:12
 * @LastEditTime: 2025-11-01 15:30:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
int a[107];
void solve()
{
    cin>>n;
    map<int,int> cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        bool ok=1;
        int res=0;
        for(auto [x,y]:cnt)
        {
            if(y<i) res+=y;
            else res+=y-i;
        }
        if(ok) ans=max(ans,n-res);
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