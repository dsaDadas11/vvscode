/*
 * @Author: dsaDadas11
 * @Date: 2025-03-27 15:20:49
 * @LastEditTime: 2025-03-27 15:21:03
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
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+1+2*n);
    cout<<a[2*n]<<' ';
    int sum=0;
    for(int i=1;i<=2*n-2;i++)
    {
        if(i&1) sum-=a[i];
        else sum+=a[i];
        cout<<a[i]<<' ';
    }
    cout<<a[2*n]+a[2*n-1]+sum<<' '<<a[2*n-1]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}