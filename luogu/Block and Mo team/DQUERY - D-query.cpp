/*
 * @Author: dsaDadas11
 * @Date: 2024-11-24 18:42:35
 * @LastEditTime: 2024-11-24 19:58:14
 * @Description: go for it!
 */
// URL: https://www.luogu.com.cn/problem/SP3267
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
int ans[N];
int len;
struct op
{
	int idx;
	int l,r;
	bool operator<(const op& that) const
	{
		if((l-1)/len!=(that.l-1)/len) return l<that.l;
		if(((l-1)/len+1)&1) return r<that.r;
		return r>that.r;
	}
}q[N];
int cnt[N];
int res;
void add(int x)
{
	if(cnt[x]==0) res++;
	cnt[x]++;
}
void del(int x)
{
	cnt[x]--;
	if(cnt[x]==0) res--;
}
void solve()
{
	cin>>n;
	len=sqrt(n);
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].idx=i;
	}
	sort(q+1,q+1+m);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		while(q[i].l<l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(q[i].r<r) del(a[r--]);

		ans[q[i].idx]=res;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}