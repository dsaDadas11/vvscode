/*
 * @Author: dsaDadas11
 * @Date: 2025-03-07 18:06:52
 * @LastEditTime: 2025-03-07 18:07:31
 * @Description: go for it!
 */
/*
 解题思路：
 枚举删 i位置的前缀正数和后缀负数
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
int pre[N],suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    suf[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if(a[i]>0) pre[i]+=a[i];
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1];
        if(a[i]<0) suf[i]-=a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,pre[i]+suf[i]);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}