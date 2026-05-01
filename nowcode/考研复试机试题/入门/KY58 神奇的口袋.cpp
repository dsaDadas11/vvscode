/*
 * @Author: dsaDadas11
 * @Date: 2026-01-20 11:09:35
 * @LastEditTime: 2026-01-20 11:09:43
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
int a[27];
int f[47];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=40;j>=a[i];j--)
        {
            f[j]+=f[j-a[i]];
        }
    }
    cout<<f[40]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}