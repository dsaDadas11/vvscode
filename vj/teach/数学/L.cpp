/*
 * @Author: dsaDadas11
 * @Date: 2025-10-17 20:36:50
 * @LastEditTime: 2025-10-17 20:37:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e6+7;
constexpr int M=2e3+7;
int n,p;
int inv[N];
void solve()
{
    cin>>n>>p;
    inv[1]=1;
    for(int i=2;i<=n;i++)
    {
        inv[i]=(p-p/i)*inv[p%i]%p;
    }

    for(int i=1;i<=n;i++) cout<<inv[i]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}