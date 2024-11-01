/*
 * @Author: dsaDadas11
 * @Date: 2024-03-05 20:18:16
 * @LastEditTime: 2024-03-05 20:20:51
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define GL (rt<<1)
#define GR ((rt<<1)|1)
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int a[N],b[N];
struct Tree
{
	int l,r,num;
}t[N<<2];
void push_up(int rt)
{
	t[rt].num=t[GL].num+t[GR].num;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(GL,l,mid);
	build(GR,mid+1,r);
}
void update(int rt,int pos,int num)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].num+=num;
		return;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(pos<=mid) update(GL,pos,num);
	else update(GR,pos,num);
	push_up(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r) return t[rt].num;
	int ans=0;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid) ans+=query(GL,l,r);
	if(mid+1<=r) ans+=query(GR,l,r);
	return ans;
}
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int len=unique(b+1,b+1+n)-(b+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+n,a[i])-b;
	}
	build(1,1,n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		update(1,a[i],1);
		if(a[i]==len) continue;
		ans+=query(1,a[i]+1,n);
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
/*
solve()函数中把build(1,1,len)和ans+=query(1,a[i]+1,len)中的n改成len就对了
*/