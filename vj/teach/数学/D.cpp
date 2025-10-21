/*
 * @Author: dsaDadas11
 * @Date: 2025-10-11 19:49:57
 * @LastEditTime: 2025-10-11 19:50:05
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
int cnt;
int a[N],p[N];
int dp[N];
void init()
{
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
        {
            a[p[j]*i]=1;
            if(i%p[j]==0) break;
        }
    }

    dp[0]=1;
    for(int j=1;j<=cnt;j++)
    {
        if(p[j]>200) break;
        for(int i=p[j];i<=200;i++)
        {
            dp[i]+=dp[i-p[j]];
        }
    }
}
int n;
void solve()
{
    while(cin>>n)
    {
        cout<<dp[n]<<endl;
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