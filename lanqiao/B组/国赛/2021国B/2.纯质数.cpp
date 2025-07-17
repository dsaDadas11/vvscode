/*
 * @Author: dsaDadas11
 * @Date: 2025-06-14 11:58:39
 * @LastEditTime: 2025-06-14 11:58:58
 * @Description: go for it!
 */
/*
 0 也不算纯素数
 也可以先判断纯素数 再判断整体是否为素数，这样更快
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=20210606;
constexpr int M=2e3+7;
int cnt;
int a[N],p[N];
void init()
{
    a[1]=1,a[0]=1;
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
        {
            a[p[j]*i]=p[j];
            if(i%p[j]==0) break;
        }
    }
}
void solve()
{
    int ans=0;
    for(int i=1;i<=cnt;i++)
    {
        bool ok=1;
        while(p[i])
        {
            if(a[p[i]%10])
            {
                ok=0;
                break;
            }
            p[i]/=10;
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}