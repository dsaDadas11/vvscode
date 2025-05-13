/*
 * @Author: dsaDadas11
 * @Date: 2025-05-13 19:30:19
 * @LastEditTime: 2025-05-13 19:30:40
 * @Description: go for it!
 */
// URL：https://codeforces.com/gym/101002
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
struct op
{
    int w,h,q;
}p[17];
int f[17][1<<15];
int cost[1<<15];
void solve()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].w>>p[i].h>>p[i].q;
    }
    memset(f,0x3f,sizeof f);
    for(int i=0;i<(1<<n);i++)
    {
        int mw=0,mh=0;
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1)
            {
                mw=max(mw,p[j].w);
                mh=max(mh,p[j].h);
            }
        }

        for(int j=0;j<n;j++)
        {
            if((i>>j)&1)
            {
                cost[i]+=p[j].q*(mw*mh-p[j].w*p[j].h);
            }
        }
    }

    f[0][0]=0;
    for(int i=1;i<=k;i++)
    {
        for(int u=0;u<(1<<n);u++)
        {
            f[i][u]=f[i-1][u]; // 一定要转移，不然 wa
            for(int s=u;s;s=(s-1)&u)
            {
                f[i][u]=min(f[i][u],f[i-1][u^s]+cost[s]);
            }
        }
    }
    
    cout<<f[k][(1<<n)-1]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}