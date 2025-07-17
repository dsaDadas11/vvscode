/*
 * @Author: dsaDadas11
 * @Date: 2025-06-13 12:53:40
 * @LastEditTime: 2025-06-13 12:53:48
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n,m;
int fa[N],dist[N];
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int find_fa(int x)
{
    if(fa[x]!=x)
    {
        int fax=find_fa(fa[x]);
        dist[x]=dist[x]*dist[fa[x]]%mod;
        fa[x]=fax;
    }
    return fa[x];
}
bool merge_set(int x,int y,int c,int d)
{
    int fax=find_fa(x);
    int fay=find_fa(y);

    if(fax!=fay)
    {
        dist[fay]=d*quickpow(c*dist[y]%mod,mod-2)%mod;
        fa[fay]=x;
        return 1;
    }
    else
    {
        int t1=dist[x]*quickpow(dist[y],mod-2)%mod;
        int t2=c*quickpow(d,mod-2)%mod;
        if(t1==t2) return 1;
        return 0;
    }
}
int cnt;
void solve()
{
    cnt++;
    cout<<"Case #"<<cnt<<": ";
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,dist[i]=1;

    int x,y,c,d;
    bool ok=1;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>c>>d;
        if(!merge_set(x,y,c,d)) ok=0;
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}