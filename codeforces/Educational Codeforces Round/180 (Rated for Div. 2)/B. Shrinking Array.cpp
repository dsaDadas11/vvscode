/*
 * @Author: dsaDadas11
 * @Date: 2025-07-17 15:52:23
 * @LastEditTime: 2025-07-17 15:52:30
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
int a[M];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(abs(a[i]-a[i-1])<=1)
        {
            cout<<0<<endl;
            return;
        }
    }
    for(int i=2;i<n;i++)
    {
        if((a[i]>=a[i-1]&&a[i]>=a[i+1])||(a[i]<=a[i-1]&&a[i]<=a[i+1]))
        {
            cout<<1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}