/*
 * @Author: dsaDadas11
 * @Date: 2025-10-12 11:58:52
 * @LastEditTime: 2025-10-12 11:59:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int cnt;
int a[N],p[N];
void init()
{
    a[0]=1;
    a[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
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
    for(int i=2;i<=n;i+=2)
    {
        for(int j=1;j<=cnt&&p[j]<=i;j++)
        {
            if(!a[i-p[j]])
            {
                cout<<i<<"="<<p[j]<<"+"<<i-p[j]<<endl;
                break;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}