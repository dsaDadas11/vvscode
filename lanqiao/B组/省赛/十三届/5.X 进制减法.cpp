/*
 * @Author: dsaDadas11
 * @Date: 2025-04-07 19:01:14
 * @LastEditTime: 2025-04-07 19:01:44
 * @Description: go for it!
 */
/*
 解题思路：
 每一位都需要最小进制
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n;
int ma,mb;
int a[N],b[N];
void solve()
{
    cin>>n;
    cin>>ma;
    for(int i=ma;i>=1;i--) cin>>a[i];
    cin>>mb;
    for(int i=mb;i>=1;i--) cin>>b[i];

    int base=1;
    int ans=0;
    for(int i=1;i<=max(ma,mb);i++)
    {
        ans+=(a[i]-b[i])*base;
        ans%=mod;
        base*=max(max(a[i],b[i])+1,2LL);
        base%=mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}