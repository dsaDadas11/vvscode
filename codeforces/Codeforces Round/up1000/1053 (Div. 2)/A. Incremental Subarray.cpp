/*
 * @Author: dsaDadas11
 * @Date: 2025-11-02 11:48:47
 * @LastEditTime: 2025-11-02 11:48:55
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[207];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<m;i++)
    {
        if(a[i]>=a[i+1])
        {
            cout<<1<<endl;
            return;
        }
    }

    cout<<n-a[m]+1<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}