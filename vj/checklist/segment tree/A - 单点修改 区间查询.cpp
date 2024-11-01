/*
 * @Author: dsaDadas11
 * @Date: 2024-02-22 21:12:37
 * @LastEditTime: 2024-02-22 21:12:43
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define GL (root<<1)
#define GR ((root<<1)|1)
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n,m,a[N];
struct Tree
{
	int left,right,sum;
}tree[N<<2];
void push_up(int root)
{
	tree[root].sum=tree[GL].sum+tree[GR].sum;
}
void build(int root,int left,int right)
{
	tree[root].left=left;
	tree[root].right=right;
	if(left==right)
	{
		tree[root].sum=a[left];
		return;
	}
	int mid=(left+right)>>1;
	build(GL,left,mid);
	build(GR,mid+1,right);
	push_up(root);
}
void update(int root,int pos,int val)
{
	if(tree[root].left==tree[root].right)
	{
		tree[root].sum+=val;
		return;
	}
	int mid=(tree[root].left+tree[root].right)>>1;
	if(pos<=mid) update(GL,pos,val);
	else update(GR,pos,val);
	push_up(root);
}
int query(int root,int left,int right)
{
	if(left<=tree[root].left&&tree[root].right<=right) return tree[root].sum;
	int mid=(tree[root].left+tree[root].right)>>1;
	int ans=0;
	if(left<=mid) ans+=query(GL,left,right);
	if(mid+1<=right) ans+=query(GR,left,right);
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		int op,x,y; cin>>op>>x>>y;
		if(op==1) update(1,x,y);
		else cout<<query(1,x,y)<<endl;
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
没输入
*/