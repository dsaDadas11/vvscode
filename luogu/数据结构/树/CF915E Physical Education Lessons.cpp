/*
 * @Author: dsaDadas11
 * @Date: 2025-10-07 12:50:55
 * @LastEditTime: 2025-10-07 13:03:33
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/CF915E
/*
 动态开点
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=1.5e7+5;
constexpr int M=2e3+7;
int n,q;
int root,ls[N],rs[N],tot; // 根 左右儿子 动态开点数
int sum[N],tag[N];
void pushup(int u)
{
    sum[u]=sum[ls[u]]+sum[rs[u]];
}
void pushdown(int u,int l,int r)
{
    if(tag[u]==-1) return;
    if(!ls[u]) ls[u]=++tot;
    if(!rs[u]) rs[u]=++tot;
    int mid=(l+r)>>1;
    sum[ls[u]]=tag[u]*(mid-l+1);
    sum[rs[u]]=tag[u]*(r-mid);
    tag[ls[u]]=tag[rs[u]]=tag[u];
    tag[u]=-1;
}
void upd(int &u,int l,int r,int x,int y,int k) //  根 树左右区间 修改区间 修改值 
{
    if(!u) u=++tot;
    if(x<=l&&r<=y)
    {
        sum[u]=k*(r-l+1);
        tag[u]=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) upd(ls[u],l,mid,x,y,k);
    if(mid+1<=y) upd(rs[u],mid+1,r,x,y,k);
    pushup(u);
}
int query(int u,int l,int r,int x,int y)
{
    if(!u) return 0;
    if(x<=l&&r<=y)
    {
        return sum[u];
    }
    pushdown(u,l,r);
    int ans=0;
    int mid=(l+r)>>1;
    if(x<=mid) ans+=query(ls[u],l,mid,x,y);
    if(mid+1<=y) ans+=query(rs[u],mid+1,r,x,y);
    return ans;
}
void solve()
{
    memset(tag,-1,sizeof tag);
    cin>>n>>q;
    int l,r,k;
    upd(root,1,n,1,n,1);
    while(q--)
    {
        cin>>l>>r>>k;
        k--;
        upd(root,1,n,l,r,k);
        cout<<query(root,1,n,1,n)<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}