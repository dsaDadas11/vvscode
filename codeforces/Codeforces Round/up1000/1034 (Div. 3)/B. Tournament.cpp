/*
 * @Author: dsaDadas11
 * @Date: 2025-07-16 18:40:02
 * @LastEditTime: 2025-07-16 18:40:09
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
    int n,j,k;
    cin>>n>>j>>k;
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(a[j]==maxn) cout<<"YES"<<endl;
    else
    {
        if(k==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}