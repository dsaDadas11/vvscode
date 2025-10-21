/*
 * @Author: dsaDadas11
 * @Date: 2025-10-10 17:10:23
 * @LastEditTime: 2025-10-10 17:12:57
 * @Description: go for it!
 */
/*
 背包预处理算贡献
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=900;
constexpr int M=2e3+7;
int n,k;
int f[N]; // 贡献为 m时的最小反转区间长度
int lst[N]; // 贡献为 m时的长度
void init()
{
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for(int m=1;m<N;m++)
    {
        for(int l=2;l*(l-1)/2<=m;l++)
        {
            if(f[m]>f[m-l*(l-1)/2]+l)
            {
                f[m]=f[m-l*(l-1)/2]+l;
                lst[m]=l;
            }
        }
    }
}
int a[37];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) a[i]=n-i+1;
    k=n*(n-1)/2-k;
    int i=1;
    while(i<=n&&k)
    {
        int len=lst[k];
        if(i+len-1>n) break;
        reverse(a+i,a+i+len);
        i+=len;
        k-=len*(len-1)/2;
    }
    if(k) return cout<<0<<endl,void();
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}