/*
 * @Author: dsaDadas11
 * @Date: 2025-03-22 11:13:18
 * @LastEditTime: 2025-03-22 11:13:25
 * @Description: go for it!
 */
/*
 不会做的一道题，能想到 lucas定理，但是不会数位dp
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int dfs(int now,int l,int a,int dep)
{
    if(dep==0)
    {
        if(now+1<=l&&((now+1)|a)==a) return 2;
        else return 1;
    }

    // 无限制
    if(now+(1ll<<(dep+1))-1<=l)
    {
        int tmp=__builtin_popcount(((1ll<<(dep+1))-1)&a);
        return (1ll<<tmp)%mod;
    }

    // 有限制
    int res=0;
    if((now+(1ll<<dep))<=l&&(((now+(1ll<<dep))|a)==a))
    {
        res+=dfs(now+(1ll<<dep),l,a,dep-1);
        res%=mod;
    }
    res+=dfs(now,l,a,dep-1);
    return res%mod;
}
int n;
int a[N],l[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>l[i];
    int ans=1;
    for(int i=1;i<=n;i++)
    {
       ans*=dfs(0,l[i],a[i],30);
       ans%=mod;
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