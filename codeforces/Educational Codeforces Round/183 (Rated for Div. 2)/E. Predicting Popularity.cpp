/*
 * @Author: dsaDadas11
 * @Date: 2025-10-07 20:07:28
 * @LastEditTime: 2025-10-07 20:07:55
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
constexpr int inf=2e9;
struct Tree
{
    int l,r;
    int minn;
    int tag;
} t[N<<2];
int b[N];
int cnt[N];
void pushup(int rt)
{
    t[rt].minn=min(t[ls].minn,t[rs].minn);
}
void apply(int rt,int v)
{
    t[rt].tag+=v;
    t[rt].minn+=v;
}
void pushdown(int rt)
{
    int v=t[rt].tag;
    apply(ls,v);
    apply(rs,v);
    t[rt].tag=0;
}
void build(int rt,int l,int r)
{
    t[rt]={l,r,0,0};
    if(l==r)
    {
        t[rt].minn=b[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(rt);
}
void upd(int rt,int l,int r,int k)
{
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        apply(rt,k);
        return;
    }
    pushdown(rt);
    int mid=(t[rt].l+t[rt].r)>>1;
    if(l<=mid) upd(ls,l,r,k);
    if(mid+1<=r) upd(rs,l,r,k);
    pushup(rt);
}
int query(int rt,int l,int r)
{
    if(t[rt].l>r||t[rt].r<l) return inf;
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        return t[rt].minn;
    }
    pushdown(rt);
    return min(query(ls,l,r),query(rs,l,r));
}
int n,m;
int ac,dr;
int a[N],d[N];
void solve()
{
    cin>>ac>>dr;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    int v;
    for(int i=1;i<=n;i++)
    {
        v=max(0,a[i]-ac)+max(0,d[i]-dr)+1; // 向右偏移 1位
        v=min(v,n+2);
        cnt[v]++;
    }
    int pre=0;
    for(int i=1;i<=n+2;i++)
    {
        b[i]=pre-(i-1);
        pre+=cnt[i];
    }
    // 建树
    build(1,1,n+3);
    cin>>m;
    while(m--)
    {
        int k;
        cin>>k;

        v=max(0,a[k]-ac)+max(0,d[k]-dr)+1; // 向右偏移 1位
        v=min(v,n+2);
        upd(1,v+1,n+3,-1);

        cin>>a[k]>>d[k];
        v=max(0,a[k]-ac)+max(0,d[k]-dr)+1; // 向右偏移 1位
        v=min(v,n+2);
        upd(1,v+1,n+3,1);

        int l=1,r=n+1; // p
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(query(1,1,mid)>=0) l=mid;
            else r=mid-1;
        }
        cout<<l-1<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}