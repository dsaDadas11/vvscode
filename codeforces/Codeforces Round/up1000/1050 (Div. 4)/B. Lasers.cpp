/*
 * @Author: dsaDadas11
 * @Date: 2025-09-19 10:47:13
 * @LastEditTime: 2025-09-19 10:47:24
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,x,y;
int a[N],b[N];
void solve()
{
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=m;j++) cin>>b[j];
    
    cout<<n+m<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}