/*
 * @Author: dsaDadas11
 * @Date: 2025-08-08 10:09:27
 * @LastEditTime: 2025-08-08 10:09:36
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
int a[57];
void solve()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0) ans++;
        else ans+=a[i];
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