/*
 * @Author: dsaDadas11
 * @Date: 2025-09-25 17:58:47
 * @LastEditTime: 2025-09-25 18:00:00
 * @Description: go for it!
 */
/*
 线段树二分
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m,p;
struct Tree
{
    int l,r;
    int sum,tag;
}tr[N<<2];
int a[N];
struct ask
{
    int op,l,r;
} q[N];
void pushup(int rt)
{
    tr[rt].sum=tr[ls].sum+tr[rs].sum;
}
void pushdown(int rt)
{
    if(tr[rt].tag==-1) return;
    tr[ls].sum=tr[rt].tag*(tr[ls].r-tr[ls].l+1);
    tr[rs].sum=tr[rt].tag*(tr[rs].r-tr[rs].l+1);
    tr[ls].tag=tr[rs].tag=tr[rt].tag;
    tr[rt].tag=-1;
}
void build(int rt,int l,int r,int x)
{
    tr[rt]={l,r,a[l]>=x,-1};
    if(l==r) return;
    int mid=(l+r)>>1;
    build(ls,l,mid,x);
    build(rs,mid+1,r,x);
    pushup(rt);
}
void upd(int rt,int l,int r,int k)
{
    if(tr[rt].l>r||tr[rt].r<l) return;
    if(tr[rt].l>=l&&tr[rt].r<=r)
    {
        tr[rt].sum=k*(tr[rt].r-tr[rt].l+1);
        tr[rt].tag=k;
        return;
    }
    pushdown(rt);
    upd(ls,l,r,k);
    upd(rs,l,r,k);
    pushup(rt);
}
int query(int rt,int l,int r)
{
    if(tr[rt].l>r||tr[rt].r<l) return 0;
    if(l<=tr[rt].l&&tr[rt].r<=r)
    {
        return tr[rt].sum;
    }
    pushdown(rt);
    return query(ls,l,r)+query(rs,l,r);
}
bool check(int x)
{
    build(1,1,n,x);
    for(int i=1;i<=m;i++)
    {
        auto [op,l,r]=q[i];
        int cnt=query(1,l,r);
        if(op==1)
        {
            upd(1,l,l+cnt-1,1);
            upd(1,l+cnt,r,0);
        }
        else
        {
            upd(1,l,r-cnt,0);
            upd(1,r-cnt+1,r,1);
        }
    }
    return query(1,p,p);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].op>>q[i].l>>q[i].r;
    }

    cin>>p;
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}