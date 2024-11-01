#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define GL (root<<1)
#define GR ((root<<1)|1)
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m,a[N];
struct Tree
{
	int l,r,sum;
	int tag;
}tree[N<<2];
void push_up(int root)
{
	tree[root].sum=tree[GL].sum+tree[GR].sum;
}
void build(int root,int l,int r)
{
	tree[root].l=l;
	tree[root].r=r;
	if(l==r)
	{
		tree[root].sum=a[l];
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
	tree[root].sum+=tag*(tree[root].r-tree[root].l+1);
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
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		int op; cin>>op;
		if(op==1)
		{
			int x,y,k; cin>>x>>y>>k;
			update(1,x,y,k);
		}
		else
		{
			int x,y; cin>>x>>y;
			cout<<query(1,x,y)<<endl;
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
/*
出现segment fault原因：
l<=mid 写成 mid<=l

wa的原因：
query函数没加 push_down(root);
*/