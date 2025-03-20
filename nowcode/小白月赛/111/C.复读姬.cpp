/*
 * @Author: dsaDadas11
 * @Date: 2025-03-08 11:10:57
 * @LastEditTime: 2025-03-08 11:11:46
 * @Description: go for it!
 */
/*
 解题思路：
 第一个注意的地方：可撤回也可不撤回
 第二个注意的地方：撤回后要确保前后的字符串相等才能拼接
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
string s[N];
int pre[N],suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    pre[1]=1,suf[n]=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]==s[i-1]) pre[i]=pre[i-1]+1;
        else pre[i]=1;
    }
    for(int i=n-1;i>=1;i--)
    {
        if(s[i]==s[i+1]) suf[i]=suf[i+1]+1;
        else suf[i]=1;
    }
    int ans=0;
    // 撤回
    for(int i=2;i<n;i++)
    {
        if(s[i-1]==s[i+1]) ans=max(ans,pre[i-1]+suf[i+1]);
    }
    // 不撤回
    for(int i=1;i<=n;i++)
    {
        ans=max({ans,pre[i],suf[i]});
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}