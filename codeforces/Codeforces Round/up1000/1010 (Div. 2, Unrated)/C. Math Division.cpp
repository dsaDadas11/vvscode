/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 15:00:16
 * @LastEditTime: 2025-04-15 15:01:53
 * @Description: go for it!
 */
/*
 解题思路：
 设 fi为第 i位进位的可能
 最后答案如果不进位，贡献为 n-1，进位贡献为 n (最多只能进 1位)
 那么 ans = (n-1)*(1-f)+n*f = n-1+f
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
string s;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=(ans*x)%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int ni(int x)
{
    return quickpow(x,mod-2);
}
void solve()
{
    cin>>n;
    cin>>s;
    reverse(s.begin(),s.end());
    s=' '+s;
    int f=0;
    int ni2=ni(2);
    for(int i=1;i<n;i++)
    {
        if(s[i]=='0') f=f*ni2%mod;
        else f=(f+1)*ni2%mod;
    }
    f=(f+n-1)%mod;
    cout<<f<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}