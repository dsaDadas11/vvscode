/*
 * @Author: dsaDadas11
 * @Date: 2025-05-05 11:36:06
 * @LastEditTime: 2025-05-05 11:36:13
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
int mx[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],mx[i]=0;
    for(int i=1;i<=n;i++)
    {
        mx[i]=max(mx[i-1],a[i]);
    }
    int sum=0;
    for(int i=n;i>=1;i--)
    {
        cout<<sum+mx[i]<<' ';
        sum+=a[i];
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}