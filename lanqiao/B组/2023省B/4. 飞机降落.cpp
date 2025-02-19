/*
 * @Author: HuangCe
 * @Date: 2025-02-17 14:44:49
 * @LastEditTime: 2025-02-17 14:45:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int t[17],d[17],l[17];
int a[17];
bool vis[17];
bool ok;
bool check()
{
    int ed=t[a[1]]+l[a[1]];
    for(int i=2;i<=n;i++)
    {
        int idx=a[i];
        if(ed-t[idx]>d[idx]) return 0;
        if(ed<t[idx]) ed=t[idx];
        ed+=l[idx];
    }
    return 1;
}
void dfs(int x)
{
    if(x==n+1)
    {
        if(check()) ok=1;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        vis[i]=1;
        a[x]=i;
        dfs(x+1);
        vis[i]=0;
    }
}
void solve()
{
    cin>>n;
    ok=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i]>>d[i]>>l[i];
        vis[i]=0;
        a[i]=0;
    }
    dfs(1);
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}