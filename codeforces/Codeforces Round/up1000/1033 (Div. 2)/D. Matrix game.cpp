/*
 * @Author: dsaDadas11
 * @Date: 2025-07-22 19:09:03
 * @LastEditTime: 2025-07-22 19:26:20
 * @Description: go for it!
 */
/*
 解题思路：
 首先看行，要从行中找到 a个相同的元素最少需要 k*(a-1)+1行(鸽巢定理)
 然后在列中要保证带有此 a个相同元素的列有 b个
 我们先看要有 a个相同元素就是 C(n,a)个，又有 k个这样的相同元素，也就是 k*C(n,a)个，
 再根据鸽巢定理可得需要有 k*C(n,a)*(b-1)+1个列(保证这 b个列元组是相同的)

 因为 n非常大，需要用 lucas定理计算
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return ans;
}
int C(int n,int m)
{
    if(m>n||m<0||n<0) return 0;
    int ans=1;
    for(int i=1,j=n;i<=m;i++,j--)
    {
        ans=ans*j%mod;
        ans=ans*quickpow(i,mod-2)%mod;
    }
    return ans%mod;
}
int lucas(int n,int m)
{
    if(m==0) return 1;
    return (C(n%mod,m%mod)*lucas(n/mod,m/mod))%mod;
}
int a,b,k;
void solve()
{
    cin>>a>>b>>k;
    int n=k*(a-1)+1;
    int ans=n%mod;
    int m=(k*lucas(ans,a)%mod)*(b-1)+1;
    m%=mod;
    cout<<ans<<' '<<m<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}