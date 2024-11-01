/*
 * @Author: dsaDadas11
 * @Date: 2024-10-15 19:59:53
 * @LastEditTime: 2024-10-15 20:03:07
 * @Description: go for it!
 */
// URL:https://vjudge.net/problem/SPOJ-DQUERY#google_vignette
/*
 解题思路：
 寻找区间中不同元素的个数的模板题，
 我们用离线查询，将询问以r从小到大排序，
 然后用树状数组+差分维护，
 如果一个数有前驱节点，那么就将前驱节点的值-1 (变为0)，此节点的值+1，保证区间[1,i]只有一个这个数 
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N],tr[N];
struct query
{
	int l,r;
	int idx;
	bool operator<(const query&that) const
	{
		return r<that.r;
	}
}q[N];
int lowbit(int x)
{
	return x&(-x);
}
void add(int p,int val)
{
	for(int i=p;i<N;i+=lowbit(i)) tr[i]+=val;
}
int ask(int p)
{
	int ans=0;
	for(int i=p;i;i-=lowbit(i)) ans+=tr[i];
	return ans;
}
int ans[N];
int pre[N],last[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		last[i]=pre[a[i]];
		pre[a[i]]=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++) cin>>q[i].l>>q[i].r,q[i].idx=i;
	sort(q+1,q+1+m);
	int l=0;
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].r)
		{
			l++;
			if(last[l]) add(last[l],-1);
			add(l,1);
		}
		ans[q[i].idx]=ask(q[i].r)-ask(q[i].l-1);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}