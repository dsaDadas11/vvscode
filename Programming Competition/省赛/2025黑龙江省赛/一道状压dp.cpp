/*
 * @Author: dsaDadas11
 * @Date: 2025-09-04 17:25:54
 * @LastEditTime: 2025-09-04 17:26:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n,m;
void solve()
{
    cin>>n>>m;
    vector<vector<int> > s(1<<8);
    for(int i=0;i<(1<<n);i++)
    {
        if((i&(i>>1))) continue;
        if((i>>(n-1))&1) continue;
        for(int j=0;j<(1<<n);j++)
        {
            if((j&(j>>1))) continue;
            if(i&j) continue;
            if((i&(j<<1))||(i&(j>>1))) continue;
            if((j>>(n-1))&1) continue;
            s[i].push_back(j);
        }
    }
    vector<vector<int> > f(m+2,vector<int>(1<<8));
    f[0][0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            if((j>>(n-1))&1) continue;
            for(auto k:s[j])
            {
                f[i][j]+=f[i-1][k];
                f[i][j]%=mod;
            }
        }
    }
    cout<<f[m][0]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}