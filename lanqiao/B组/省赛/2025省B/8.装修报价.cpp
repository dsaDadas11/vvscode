/*
 * @Author: dsaDadas11
 * @Date: 2025-04-12 20:47:36
 * @LastEditTime: 2025-04-12 20:50:56
 * @Description: go for it!
 */
/*
 解题思路：
 发现 (a^b^c) - d?e?f
 与   (a^b^c) + d?e?f 可以抵消后面，变为 2*(a^b^c)
 因此我们只需要计算前缀异或和后面的操作数次方 (比如这里为 3的 2次方)
 然后就能得出答案
 如果前面的异或改成 -或者 +呢，那么就会有对应的 +或 -将这个操作符后面的内容全部抵消，因此只需算全为异或的情况
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n;
int a[N];
int p[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    p[0]=1;
    for(int i=1;i<=n+3;i++)
    {
        p[i]=(p[i-1]*3)%mod;
    }
    int ans=0;
    int tmp=0;
    for(int i=1;i<n;i++)
    {
        tmp^=a[i];
        ans+=tmp*2*p[n-i-1];
        ans%=mod;
    }
    tmp^=a[n];
    ans=(ans+tmp)%mod;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}