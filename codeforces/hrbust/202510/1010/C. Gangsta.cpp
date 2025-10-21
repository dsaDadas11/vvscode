/*
 * @Author: dsaDadas11
 * @Date: 2025-10-10 21:38:21
 * @LastEditTime: 2025-10-10 21:50:13
 * @Description: go for it!
 */
/*
 max(x,y) = (x + y + abs(x - y) ) / 2
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s;
int f[N];
int sum[N];
void solve()
{
    cin>>n;
    cin>>s;
    s=' '+s;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(n-i+1)*(n+2-i);
    }
    ans/=2;

    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+(s[i]=='0'?1:-1);
    }
    sort(f+1,f+1+n);

    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+f[i];
    }

    int res=0;
    for(int i=1;i<=n;i++) res+=abs(f[i]);
    for(int i=1;i<=n;i++)
    {
        int d1=i-1;
        int d2=n-i;
        res+=d1*f[i]-d2*f[i]+abs(f[i]);
        
        int x=sum[i-1],y=sum[n]-sum[i];
        res+=y-x;
    }
    res/=2;

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=i;j<=n;j++)
    //     {
    //         ans+=abs(f[i]-f[j]);
    //     }
    // }
    cout<<(ans+res)/2<<endl;

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}