/*
 * @Author: dsaDadas11
 * @Date: 2025-03-27 14:47:10
 * @LastEditTime: 2025-03-27 14:47:19
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
void solve()
{
    cin>>n>>k;
    if(k&1)
    {
        for(int i=1;i<n;i++) cout<<n<<' ';
        cout<<n-1<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(i==n-1) cout<<n<<' ';
            else cout<<n-1<<' ';
        }
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}