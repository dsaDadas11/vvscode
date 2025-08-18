/*
 * @Author: dsaDadas11
 * @Date: 2025-07-29 15:12:45
 * @LastEditTime: 2025-07-29 15:12:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define GL (root<<1)
#define GR ((root<<1)|1)
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m,r,p;
vector<int> g[N];
int fa[N],son[N],sz[N],dep[N];
int top[N],idx[N],nw[N],cnt,w[N];
struct Tree
{
	int l,r,sum;
	int tag;
}tree[N<<2];
void push_up(int root)
{
	tree[root].sum=(tree[GL].sum+tree[GR].sum)%p;
}
void build(int root,int l,int r)
{
	tree[root].l=l;
	tree[root].r=r;
	if(l==r)
	{
		tree[root].sum=nw[l]%p;
		return;
	}
	int mid=(l+r)>>1;
	build(GL,l,mid);
	build(GR,mid+1,r);
	push_up(root);
}
void add_tag(int root,int tag)
{
	tree[root].tag+=tag;
	tree[root].sum+=tag*(tree[root].r-tree[root].l+1)%p;

    tree[root].tag%=p;
    tree[root].sum%=p;
}
void push_down(int root)
{
	if(tree[root].l==tree[root].r) return;
	if(tree[root].tag)
	{
		add_tag(GL,tree[root].tag);
		add_tag(GR,tree[root].tag);
		tree[root].tag=0;
	}
}
void update(int root,int l,int r,int val)
{
	if(l<=tree[root].l&&tree[root].r<=r)
	{
		add_tag(root,val);
		return;
	}
	push_down(root);
	int mid=(tree[root].l+tree[root].r)>>1;
	if(l<=mid) update(GL,l,r,val);
	if(mid+1<=r) update(GR,l,r,val);
	push_up(root);
}
int query(int root,int l,int r)
{
	if(l<=tree[root].l&&tree[root].r<=r) return tree[root].sum;
	push_down(root);
	int mid=(tree[root].l+tree[root].r)>>1;
	int ans=0;
	if(l<=mid) ans+=query(GL,l,r);
	if(mid+1<=r) ans+=query(GR,l,r);
	return ans%p;
}
void dfs1(int u,int fax)
{
    dep[u]=dep[fax]+1;
    fa[u]=fax,sz[u]=1;
    for(auto v:g[u])
    {
        if(v==fax) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t)
{
    top[u]=t,idx[u]=++cnt,nw[cnt]=w[u];
    if(!son[u]) return;
    dfs2(son[u],t);
    for(auto v:g[u])
    {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int query_path(int u,int v)
{
    int res=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res+=query(1,idx[top[u]],idx[u]);
        res%=p;
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    res+=query(1,idx[v],idx[u]);
    return res%p;
}
void update_path(int u,int v,int k)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        update(1,idx[top[u]],idx[u],k);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    update(1,idx[v],idx[u],k);
}
void update_tree(int u,int k)
{
    update(1,idx[u],idx[u]+sz[u]-1,k);
}
int query_tree(int u)
{
    return query(1,idx[u],idx[u]+sz[u]-1);
}
void solve()
{
    cin>>n>>m>>r>>p;
    for(int i=1;i<=n;i++) cin>>w[i];
    int u,v,val,op;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(r,0);
    dfs2(r,0);
    build(1,1,n);
    while(m--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>u>>v>>val;
            update_path(u,v,val);
        }
        else if(op==2)
        {
            cin>>u>>v;
            cout<<query_path(u,v)%p<<endl;
        }
        else if(op==3)
        {
            cin>>u>>val;
            update_tree(u,val);
        }
        else
        {
            cin>>u;
            cout<<query_tree(u)%p<<endl;
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