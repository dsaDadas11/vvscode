/*
 * @Author: dsaDadas11
 * @Date: 2025-08-13 15:49:36
 * @LastEditTime: 2025-08-13 16:11:06
 * @Description: go for it!
 */
/*
 前置题目请看：P1220 关路灯
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
constexpr int inf=1e12; // 1e10 wa
int n,x0;
struct op
{
    int x,y,v;
    bool operator<(const op&a) const
    {
        return x<a.x;
    }
}a[N];
int sum[N];
int f[2][N][N];
void solve()
{
    cin>>n>>x0;
    for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=1;i<=n;i++) cin>>a[i].y;
    for(int i=1;i<=n;i++) cin>>a[i].v;
    a[++n]={x0,0,0};
    sort(a+1,a+1+n);

    int pos=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i].v;
        if(a[i].x==x0&&a[i].y==0) pos=i;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[0][i][j]=f[1][i][j]=-inf;
        }
    }
    f[0][pos][pos]=f[1][pos][pos]=0;

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i+k<=n;i++)
        {
            int j=i+k;
            int w1=sum[n]-(sum[j]-sum[i]);
            f[0][i][j]=a[i].y+max(f[0][i+1][j]-w1*(a[i+1].x-a[i].x),
                                  f[1][i+1][j]-w1*(a[j].x-a[i].x));

            int w2=sum[n]-(sum[j-1]-sum[i-1]);
            f[1][i][j]=a[j].y+max(f[0][i][j-1]-w2*(a[j].x-a[i].x),
                                  f[1][i][j-1]-w2*(a[j].x-a[j-1].x));
        }
    }
    cout<<fixed<<setprecision(3)<<1.0*max(f[0][1][n],f[1][1][n])/1000.0<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}