/*
 * @Author: dsaDadas11
 * @Date: 2025-08-20 11:08:39
 * @LastEditTime: 2025-08-20 11:14:27
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
int h,w,k;
int f[N][4];
void solve()
{
    int x1,y1,x2,y2;
    cin>>h>>w>>k;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2&&y1==y2) f[0][0]=1;
    if(x1==x2&&y1!=y2) f[0][1]=1;
    if(x1!=x2&&y1==y2) f[0][2]=1;
    if(x1!=x2&&y1!=y2) f[0][3]=1;

    for(int i=1;i<=k;i++)
    {
        f[i][0]=(f[i-1][1]+f[i-1][2])%mod;
        f[i][1]=(f[i-1][1]*(w-2)%mod+f[i-1][0]*(w-1)%mod+f[i-1][3])%mod;
        f[i][2]=(f[i-1][2]*(h-2)%mod+f[i-1][0]*(h-1)%mod+f[i-1][3])%mod;
        f[i][3]=(f[i-1][1]*(h-1)%mod+f[i-1][2]*(w-1)%mod+f[i-1][3]*(w+h-4)%mod)%mod;
    }
    
    cout<<f[k][0]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}