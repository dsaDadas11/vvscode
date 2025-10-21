/*
 * @Author: dsaDadas11
 * @Date: 2025-10-07 22:00:34
 * @LastEditTime: 2025-10-07 22:21:05
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/CF803G
/*
 动态开点
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=1e5+7;
constexpr int inf=2e9;
int n,k,q;
int lg[M],f[M][20];
void init()
{
    // 避免浮点运算，加快速度
    lg[1]=0;
    for(int i=2;i<=n;i++)
    {
        lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
    }

    for(int j=1;j<20;j++)
    {
        for(int i=0;i+(1<<j)-1<n;i++)
        {
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
int query_st(int l,int r)
{
    int k=lg[r-l+1];
    return min(f[l][k],f[r-(1<<k)+1][k]);
}
int ask_st(int l,int r)
{
    int d=r/n-l/n;
    if(r-l+1>=n) return query_st(0,n-1);
    l%=n,r%=n;
    if(d==1) return min(query_st(l,n-1),query_st(0,r));
    return query_st(l,r);
}
int root,ls[N],rs[N],tot; // 根 左右儿子 动态开点数
int st[N],minn[N]; // 维护的信息
void pushup(int u)
{
    minn[u]=min(minn[ls[u]],minn[rs[u]]);
}
void apply(int u,int k)
{
    st[u]=k;
    minn[u]=k;
}
void pushdown(int u,int l,int r)
{
    int mid=(l+r)>>1;
    if(!ls[u])
    {
        ls[u]=++tot;
        minn[ls[u]]=ask_st(l,mid);
    }
    if(!rs[u])
    {
        rs[u]=++tot;
        minn[rs[u]]=ask_st(mid+1,r);
    }
    if(st[u]==0) return;
    apply(ls[u],st[u]);
    apply(rs[u],st[u]);
    st[u]=0;
}
void upd(int &u,int l,int r,int x,int y,int k) //  根 树左右区间 修改区间 修改值
{
    if(!u)
    {
        u=++tot;
        minn[u]=ask_st(l,r);
    }
    if(x<=l&&r<=y)
    {
        apply(u,k);
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) upd(ls[u],l,mid,x,y,k);
    if(mid+1<=y) upd(rs[u],mid+1,r,x,y,k);
    pushup(u);
}
int query_sec(int u,int l,int r,int x,int y)
{
    if(x>r||l>y) return inf; // 最好加上，容易死循环
    if(!u) return ask_st(max(l,x),min(r,y)); // 该范围没更新过
    if(x<=l&&r<=y)
    {
        return minn[u];
    }
    pushdown(u,l,r);
    int mid=(l+r)>>1;
    int ans=inf;
    if(x<=mid) ans=min(ans,query_sec(ls[u],l,mid,x,y));
    if(mid+1<=r) ans=min(ans,query_sec(rs[u],mid+1,r,x,y));
    return ans;
}
void solve()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>f[i][0];
    init();
    cin>>q;
    int op,l,r,x;
    while(q--)
    {
        cin>>op>>l>>r;
        l--,r--;
        if(op==1)
        {
            cin>>x;
            upd(root,0,n*k-1,l,r,x);
        }
        else
        {
            cout<<query_sec(root,0,n*k-1,l,r)<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}