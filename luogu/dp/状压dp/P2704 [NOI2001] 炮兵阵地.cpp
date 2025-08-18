/*
 * @Author: dsaDadas11
 * @Date: 2025-08-18 15:24:26
 * @LastEditTime: 2025-08-18 15:24:36
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1<<10;
int n,m;
int mp[M],num[M];
int f[2][M][M];
void solve()
{
    cin>>n>>m;
    char c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c;
            if(c=='P') mp[i]+=1<<(m-j);
        }
    }

    vector<int> s;
    for(int i=0;i<(1<<m);i++)
    {
        if((i&(i>>1))||(i&(i>>2))) continue;
        s.push_back(i);

        for(int j=0;j<m;j++)
        {
            num[i]+=(i>>j)&1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(auto a:s)
        {
            for(auto b:s)
            {
                for(auto c:s)
                {
                    if(a&b||a&c||b&c) continue;
                    if(((a&mp[i])!=a)||((b&mp[i-1])!=b)) continue;
                    f[i&1][a][b]=max(f[i&1][a][b],f[(i-1)&1][b][c]+num[a]);
                }
            }
        }
    }
    int ans=0;
    for(auto a:s)
    {
        for(auto b:s)
        {
            ans=max(ans,f[n&1][a][b]);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}