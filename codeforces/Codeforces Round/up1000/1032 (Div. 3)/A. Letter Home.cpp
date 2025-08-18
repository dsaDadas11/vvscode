/*
 * @Author: dsaDadas11
 * @Date: 2025-08-01 11:35:45
 * @LastEditTime: 2025-08-01 11:35:54
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,s;
int x[17];
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>x[i];
    int ans=0;
    sort(x+1,x+1+n);
    ans=abs(x[n]-s)+abs(x[n]-x[1]);
    ans=min(ans,abs(x[1]-s)+abs(x[1]-x[n]));
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}