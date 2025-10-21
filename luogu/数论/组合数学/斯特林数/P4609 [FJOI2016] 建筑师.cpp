/*
 * @Author: dsaDadas11
 * @Date: 2025-09-18 21:24:41
 * @LastEditTime: 2025-09-18 21:24:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e4+7;
constexpr int M=2e2+7;
constexpr int mod=1e9+7;
int n,a,b;
int s[N][M],c[M][M];
void init()
{
    s[0][0]=1;
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<M;j++)
        {
            s[i][j]=(s[i-1][j-1]+(i-1)*(s[i-1][j])%mod)%mod;
        }
    }

    for(int i=0;i<M;i++) c[i][0]=1,c[i][i]=1;
    for(int i=1;i<M;i++)
    {
        for(int j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}
void solve()
{
    cin>>n>>a>>b;
    cout<<s[n-1][a+b-2]*c[a+b-2][a-1]%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}