/*
 * @Author: dsaDadas11
 * @Date: 2025-03-26 19:18:04
 * @LastEditTime: 2025-03-26 19:18:13
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
    int t=sqrt(n*(n+1)/2);
    if(n*(n+1)/2==t*t)
    {
        cout<<"-1"<<endl;
        return;
    }

    for(int i=1;i<=n;i++) a[i]=i;
    int sum=0;
    for(int i=1;i<n;i++)
    {
        t=sqrt(sum+a[i]);
        if(sum+a[i]==t*t) swap(a[i],a[i+1]);
        sum+=a[i];
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}