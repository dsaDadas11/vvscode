/*
 * @Author: dsaDadas11
 * @Date: 2025-09-27 18:46:42
 * @LastEditTime: 2025-09-27 18:46:49
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
void solve()
{
    cin>>n>>m;
    int mod=n*m;
    if(gcd(n,m)==1)
    {
        cout<<"Yes"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<(i*m+1)%mod<<' ';
        }
        cout<<endl;
        for(int i=0;i<m;i++)
        {
            cout<<(i*n+1)%mod<<' ';
        }
        cout<<endl;
        return;
    }
    cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}