/*
 * @Author: dsaDadas11
 * @Date: 2025-02-03 19:50:11
 * @LastEditTime: 2025-02-03 19:50:19
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
int a[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[n+1]=0;
    if(n==k)
    {
        for(int i=2;i<=n;i+=2)
        {
            if(a[i]!=i/2)
            {
                cout<<(i/2)<<endl;
                return;
            }
        }
        cout<<n/2+1<<endl;
        return;
    }
    for(int i=2;i<=n-k+2;i++)
    {
        if(a[i]!=1)
        {
            cout<<'1'<<endl;
            return;
        }
    }
    cout<<'2'<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}