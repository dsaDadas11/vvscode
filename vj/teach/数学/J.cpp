/*
 * @Author: dsaDadas11
 * @Date: 2025-10-15 21:14:48
 * @LastEditTime: 2025-10-15 21:15:37
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=1e8+5;
constexpr int M=2e3+7;
int a[N],p[N],cnt;
void init()
{
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&(ll)p[j]*i<N;j++)
        {
            a[p[j]*i]=1;
            if(!i%p[j]) break;
        }
    }
}
int n;
void solve()
{
    cin>>n;
    cout<<p[n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    cin>>n;
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}