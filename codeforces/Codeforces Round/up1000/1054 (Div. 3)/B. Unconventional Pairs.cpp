/*
 * @Author: dsaDadas11
 * @Date: 2025-11-06 13:29:33
 * @LastEditTime: 2025-11-06 13:29:39
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
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);

    int d=0;
    for(int i=2;i<=n;i+=2)
    {
        d=max(d,a[i]-a[i-1]);
    }
    cout<<d<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}