/*
 * @Author: dsaDadas11
 * @Date: 2025-01-20 00:22:07
 * @LastEditTime: 2025-01-20 00:22:22
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
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bool flag=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            flag=0;
        }
    }
    if(flag) return cout<<"YES"<<endl,void();
    int tmp;
    for(int i=1;i<n;i++)
    {
        if(a[i]<=a[i+1])
        {
            tmp=min(a[i],a[i+1]);
            a[i]-=tmp;
            a[i+1]-=tmp;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}