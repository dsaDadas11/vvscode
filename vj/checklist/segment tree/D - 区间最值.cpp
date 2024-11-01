#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define GL (root<<1)
#define GR ((root<<1)|1)
using namespace std;
constexpr int N=2e6+7;
constexpr int M=2e3+7;
int n,m,a[N];
struct Tree
{
	int l,r;
	int sum; //区间和
	int ma; //区间最大值
	int se; //严格次大值
	int num; //最大值个数
	int tag; //维护区间最值操作
}tree[N<<2];
void push_up(int root)
{
	tree[root].sum=tree[GL].sum+tree[GR].sum;
	if(tree[GL].ma==tree[GR].ma)
	{
		tree[root].ma=tree[GL].ma;
		tree[root].num=tree[GL].num+tree[GR].num;
		tree[root].se=max(tree[GL].se,tree[GR].se);
	}
	else if(tree[GL].ma>tree[GR].ma)
	{
		tree[root].ma=tree[GL].ma;
		tree[root].num=tree[GL].num;
		tree[root].se=max(tree[GL].se,tree[GR].ma);
	}
	else
	{
		tree[root].ma=tree[GR].ma;
		tree[root].num=tree[GR].num;
		tree[root].se=max(tree[GL].ma,tree[GR].se);
	}
}
void build(int root,int l,int r)
{
	tree[root].l=l;
	tree[root].r=r;
	tree[root].tag=-1;
	if(l==r)
	{
		tree[root].sum=a[l];
		tree[root].ma=a[l];
		tree[root].se=-1;
		tree[root].num=1;
		return;
	}
	int mid=(l+r)>>1;
	build(GL,l,mid);
	build(GR,mid+1,r);
	push_up(root);
}
void add_tag(int root,int val)
{
	if(val>=tree[root].ma) return;
	tree[root].sum-=tree[root].num*(tree[root].ma-val);
	tree[root].ma=val;
	tree[root].tag=val;
}
void push_down(int root)
{
	if(~tree[root].tag)
	{
		add_tag(GL,tree[root].tag);
		add_tag(GR,tree[root].tag);
		tree[root].tag=-1;
	}
}
void update(int root,int l,int r,int val)
{
	if(tree[root].l>r||tree[root].r<l||tree[root].ma<=val) return;
	if(l<=tree[root].l&&tree[root].r<=r&&tree[root].se<val)
	{
		add_tag(root,val);
		return;
	}
	push_down(root);
	update(GL,l,r,val);
	update(GR,l,r,val);
	push_up(root);
}
int find_max(int root,int l,int r)
{
	if(tree[root].l>r||tree[root].r<l) return 0;
	if(l<=tree[root].l&&tree[root].r<=r) return tree[root].ma;
	push_down(root);
	return max(find_max(GL,l,r),find_max(GR,l,r));
}
int find_sum(int root,int l,int r)
{
	if(tree[root].l>r||tree[root].r<l) return 0;
	if(l<=tree[root].l&&tree[root].r<=r) return tree[root].sum;
	push_down(root);
	return find_sum(GL,l,r)+find_sum(GR,l,r);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,t;
		cin>>op;
		if(op==0)
		{
			cin>>x>>y>>t;
			update(1,x,y,t);
		}
		else if(op==1)
		{
			cin>>x>>y;
			cout<<find_max(1,x,y)<<endl;
		}
		else
		{
			cin>>x>>y;
			cout<<find_sum(1,x,y)<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}