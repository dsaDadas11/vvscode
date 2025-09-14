/*
 * @Author: dsaDadas11
 * @Date: 2025-08-23 11:43:50
 * @LastEditTime: 2025-08-23 11:44:04
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[307];
int f[307][307],g[307][307];
int s[307];
int p[307][307];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    memset(f,0x3f,sizeof f),memset(g,-0x3f,sizeof g);
    for(int i=1;i<=2*n;i++)
    {
        s[i]=s[i-1]+a[i];
        p[i][i]=i;
        f[i][i]=g[i][i]=0;
    }

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=2*n-len+1;i++)
        {
            int j=i+len-1;
            for(int k=p[i][j-1];k<=p[i+1][j];k++)
            {
                if(f[i][j]>f[i][k]+f[k+1][j]+s[j]-s[i-1])
                {
                    f[i][j]=f[i][k]+f[k+1][j]+s[j]-s[i-1];
                    p[i][j]=k;
                }
            }
            g[i][j]=max(g[i][j-1],g[i+1][j])+s[j]-s[i-1];
        }
    }
    int minn=1e9,maxn=-1e9;
    for(int i=1;i<=n;i++)
    {
        minn=min(minn,f[i][i+n-1]);
        maxn=max(maxn,g[i][i+n-1]);
    }
    cout<<minn<<endl;
    cout<<maxn<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}