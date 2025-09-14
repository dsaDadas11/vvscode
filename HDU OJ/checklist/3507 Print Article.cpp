/*
 * @Author: dsaDadas11
 * @Date: 2025-08-22 18:51:11
 * @LastEditTime: 2025-08-22 18:51:25
 * @Description: go for it!
 */
/*
 斜率优化 dp
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int c[N],s[N];
int q[N];
int f[N];
double slope(int i,int j) // 计算斜率
{
    return 1.0*(f[j]+s[j]*s[j]-f[i]-s[i]*s[i])/(s[j]==s[i]?1e-9:s[j]-s[i]);
}
void solve()
{
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+c[i];
    }
    f[0]=0;
    
    int h=1,t=0;
    q[h]=q[t]=0;
    for(int i=1;i<=n;i++)
    {
        while(h<t&&slope(q[t],i-1)<=slope(q[t-1],q[t])) t--;
        q[++t]=i-1;
        while(h<t&&slope(q[h],q[h+1])<=2*s[i]) h++;
        int j=q[h];
        f[i]=f[j]+(s[i]-s[j])*(s[i]-s[j])+m;
    }
    cout<<f[n]<<endl;

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>n>>m){solve();}
    return 0;
}