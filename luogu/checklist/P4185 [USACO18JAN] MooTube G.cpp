/*
 * @Author: dsaDadas11
 * @Date: 2024-08-30 21:02:12
 * @LastEditTime: 2024-08-30 21:03:51
 * @Description: go for it!
 */
/*
 解题思路：
 1.首先这道题需要从大到小离线查询，然后用并查集合并并记录每个集合的元素个数
 2.一定要看清楚范围啊啊 n-1 和 q 一定要看清楚哇
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q;
struct op1
{
	int p,q,r;
	bool operator<(const op1& a) const
	{
		return r>a.r;
	}
}a[N];
struct op2
{
	int k,v;
	int idx;
	bool operator<(const op2& a) const
	{
		return k>a.k;
	}
}b[N];
int fa[N];
int sz[N];
int findfa(int x)
{
	if(x!=fa[x]) return fa[x]=findfa(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	int fax=findfa(x);
	int fay=findfa(y);
	fa[fax]=fay;
	sz[fay]+=sz[fax];
}
int ans[N];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		cin>>a[i].p>>a[i].q>>a[i].r;
	}
	for(int i=1;i<=q;i++)
	{
		b[i].idx=i;
		cin>>b[i].k>>b[i].v;
	}
	sort(a+1,a+n);
	sort(b+1,b+1+q);
	for(int i=0;i<=n;i++)
	{
		fa[i]=i;
		sz[i]=1;
	}
	int j=1;
	for(int i=1;i<=q;i++)
	{
		while(b[i].k<=a[j].r&&j<n)
		{
			merge(a[j].p,a[j].q);
			j++;
		}
		int fa1=findfa(b[i].v);
		ans[b[i].idx]=sz[fa1];
	}
	for(int i=1;i<=q;i++) cout<<ans[i]-1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}