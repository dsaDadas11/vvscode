/*
 * @Author: dsaDadas11
 * @Date: 2025-09-25 22:37:03
 * @LastEditTime: 2025-09-25 22:37:14
 * @Description: go for it!
 */
/*
 需要特判边界
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
constexpr int N=2e6+7;
constexpr int M=2e3+7;
int n,q;
int a[N];
int x[N],v[N];
int posa[N],posv[N];
struct Tree
{
    int l,r;
    int sum,cnt;
} tr[N];
void pushup(int rt)
{
    tr[rt].sum=tr[ls].sum+tr[rs].sum;
    tr[rt].cnt=tr[ls].cnt+tr[rs].cnt;
}
void build(int rt,int l,int r)
{
    tr[rt]={l,r,0,0};
    if(l==r) return;
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void upd(int rt,int p,int val,int cnt)
{
    if(tr[rt].l==tr[rt].r)
    {
        tr[rt].sum+=val;
        tr[rt].cnt+=cnt;
        return;
    }
    int mid=(tr[rt].l+tr[rt].r)>>1;
    if(p<=mid) upd(ls,p,val,cnt);
    else upd(rs,p,val,cnt);
    pushup(rt);
}
int query_val(int rt,int l,int r)
{
    if(tr[rt].l>r||tr[rt].r<l) return 0;
    if(l<=tr[rt].l&&tr[rt].r<=r)
    {
        return tr[rt].sum;
    }
    return query_val(ls,l,r)+query_val(rs,l,r);
}
int query_cnt(int rt,int l,int r)
{
    if(tr[rt].l>r||tr[rt].r<l) return 0;
    if(l<=tr[rt].l&&tr[rt].r<=r)
    {
        return tr[rt].cnt;
    }
    return query_cnt(ls,l,r)+query_cnt(rs,l,r);
}
void solve()
{
    cin>>n>>q;
    vector<pair<int,int> > vec;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vec.push_back({a[i],i});
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>v[i];
        vec.push_back({v[i],n+i});
    }
    sort(vec.begin(),vec.end());
    int len=vec.size();
    for(int i=0;i<len;i++)
    {
        auto [val,idx]=vec[i];
        if(idx<=n)
        {
            posa[idx]=i+1;
        }
        else
        {
            posv[idx-n]=i+1;
        }
    }

    build(1,1,len);
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        if(a[i]>0) cnt++;
        upd(1,posa[i],a[i],1);
    }

    for(int i=1;i<=q;i++)
    {
        int idx=x[i];
        
        int lstval=a[idx];
        int nowval=v[i];
        a[idx]=nowval;

        upd(1,posa[idx],-lstval,-1);
        upd(1,posv[i],nowval,1);

        sum-=lstval;
        if(lstval>0) cnt--;
        sum+=nowval;
        if(nowval>0) cnt++;
        
        posa[idx]=posv[i];

        if(sum<=0)
        {
            cout<<cnt+1<<endl;
            continue;
        }

        int l=1,r=len;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(query_val(1,1,mid)<=0) l=mid;
            else r=mid-1;
        }
        // while(l+1<=len&&query_val(1,1,l+1)<=0) l++;
        if(cnt==n)
        {
            cout<<1<<endl;
            continue;
        }
        int res=n-query_cnt(1,1,l);
        // cout<<"res: "<<res<<endl;
        cout<<cnt-res+1<<endl;

    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}