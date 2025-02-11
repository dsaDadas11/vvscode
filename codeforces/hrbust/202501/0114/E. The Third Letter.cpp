/*
 * @Author: dsaDadas11
 * @Date: 2025-01-15 11:09:28
 * @LastEditTime: 2025-01-15 11:10:43
 * @Description: go for it!
 */
/*
 带权并查集板子题
 注意 fa[i] 怎么初始化的，被初始化卡了半个小时。。。。
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
int a[N],b[N],c[N];
int fa[N],d[N];
int findfa(int x)
{
    if(fa[x]!=x)
    {
        int t=fa[x];
        fa[x]=findfa(fa[x]);
        d[x]+=d[t];
    }
    return fa[x];
}
// 在前面是减 后面是加
bool merge_set(int a,int b,int val)
{
    int rta=findfa(a);
    int rtb=findfa(b);
    if(rta==rtb)
    {
        if(d[a]-d[b]!=val) return 0;
    }
    else
    {
        fa[rta]=rtb;
        d[rta]=d[b]-d[a]+val;
    }
    return 1;
}
void solve()
{
    cin>>n>>m;
    for(int i=0;i<=n+5;i++) fa[i]=i,d[i]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=m;i++)
    {
        bool flag=merge_set(a[i],b[i],c[i]);
        if(!flag) return cout<<"NO"<<endl,void();
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