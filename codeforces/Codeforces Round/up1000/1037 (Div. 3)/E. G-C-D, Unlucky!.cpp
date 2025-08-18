/*
 * @Author: dsaDadas11
 * @Date: 2025-07-28 16:48:31
 * @LastEditTime: 2025-07-28 16:53:09
 * @Description: go for it!
 */
/*
 解题思路：
 忘记判断最重要的一点：所有数 gcd的前缀后缀是否相同，加上就过了
 首先对于一般情况
 gcd(p[i-1],a[i])=p[i], gcd(s[i+1],a[i])=s[i]
 那么 a[i]一定含有 p[i]和 s[i]的因子，因此先取 lcm, lc=lcm(p[i],s[i])
 再判断 gcd(p[i-1],lc)=p[i], gcd(s[i+1],lc)=s[i]是否成立即可

 其实判断 gcd(p[i],s[i+1])是否等于 s[1]即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int pre[N],suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>pre[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>suf[i];
    }
    // 判断所有数 gcd的前缀后缀是否相同
    if(pre[n]!=suf[1])
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(pre[i]>pre[i-1]||pre[i-1]%pre[i]!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(suf[i]<suf[i-1]||suf[i]%suf[i-1]!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int pg=pre[i-1];
        int sg=suf[i+1];
        int lc=lcm(pre[i],suf[i]);
        if(gcd(pre[i-1],lc)!=pre[i]&&i>1) return cout<<"NO"<<endl,void();
        if(gcd(suf[i+1],lc)!=suf[i]&&i<n) return cout<<"NO"<<endl,void();
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int pre[N],suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>pre[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>suf[i];
    }
    // 判断所有数 gcd的前缀后缀是否相同
    if(pre[n]!=suf[1])
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(pre[i]>pre[i-1]||pre[i-1]%pre[i]!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(suf[i]<suf[i-1]||suf[i]%suf[i-1]!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(gcd(pre[i],suf[i+1])!=suf[1]) return cout<<"NO"<<endl,void();
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/