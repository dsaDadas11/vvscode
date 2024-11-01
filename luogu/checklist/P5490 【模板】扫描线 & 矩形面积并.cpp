/*
 * @Author: dsaDadas11
 * @Date: 2024-10-15 16:06:14
 * @LastEditTime: 2024-10-15 16:06:26
 * @Description: go for it!
 */
/*
 解题思路：
 线段树+扫描线模板题
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define GL (rt<<1)
#define GR ((rt<<1)|1)
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int X[N<<1];
struct scanline
{
	int x1,x2;
	int y;
	int tag;
	bool operator<(const scanline& a) const
	{
		return y<a.y;
	}
}line[N<<1];
struct Tree
{
	int l,r;
	int len; // 覆盖区间长度
	int cnt; // 是否被覆盖
}tree[N<<2];
void push_up(int rt)
{
	if(tree[rt].cnt!=0)
	{
		tree[rt].len=X[tree[rt].r+1]-X[tree[rt].l]; // 右端点往右偏一位
	}
	else
	{
		tree[rt].len=tree[GR].len+tree[GL].len;
	}
}
void build(int rt,int l,int r)
{
	tree[rt].l=l,tree[rt].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(GL,l,mid);
	build(GR,mid+1,r);
}
void add(int rt,int l,int r,int tag)
{
	if(l>tree[rt].r||tree[rt].l>r) return;
	if(l<=tree[rt].l&&tree[rt].r<=r)
	{
		tree[rt].cnt+=tag;
		push_up(rt);
		return;
	}
	add(GL,l,r,tag);
	add(GR,l,r,tag);
	push_up(rt);
}
void solve()
{
	cin>>n;
	int x1,y1,x2,y2;
	for(int i=1;i<=n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		line[i]={x1,x2,y1,1};
		line[i+n]={x1,x2,y2,-1};
		X[i]=x1;
		X[i+n]=x2;
	}
	n<<=1;
	sort(line+1,line+1+n);
	sort(X+1,X+1+n);
	int len=unique(X+1,X+1+n)-(X+1);
	build(1,1,len-1);
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int L=lower_bound(X+1,X+1+len,line[i].x1)-X;
		int R=lower_bound(X+1,X+1+len,line[i].x2)-X;
		add(1,L,R-1,line[i].tag); // 右端点往左偏一位
		ans+=(line[i+1].y-line[i].y)*tree[1].len;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}