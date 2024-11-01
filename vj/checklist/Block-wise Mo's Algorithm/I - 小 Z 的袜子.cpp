/*
 * @Author: dsaDadas11
 * @Date: 2024-01-21 13:31:07
 * @LastEditTime: 2024-01-21 13:31:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,m,len,sum,a[N],cnt[N],ans1[N],ans2[N];
struct op
{
	int l,r,id;
	bool operator<(const op&that)const
	{
		if((l-1)/len==(that.l-1)/len) return r<that.r;
		return l<that.l;
	}
}q[N];
void add(int x)
{
	sum+=cnt[x];
	cnt[x]++;
}
void del(int x)
{
	cnt[x]--;
	sum-=cnt[x];
}
void solve()
{
	cin>>n>>m;
	len=sqrt(n);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		if(q[i].l==q[i].r)
		{
			ans1[q[i].id]=0;
			ans2[q[i].id]=1;
			continue;
		}
		while(l<q[i].l) del(a[l++]);
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(r>q[i].r) del(a[r--]);
		if(sum==0)
		{
			ans1[q[i].id]=0;
			ans2[q[i].id]=1;
			continue;
		}
		ans1[q[i].id]=sum;
		ans2[q[i].id]=(r-l+1)*(r-l)/2;
		int g=gcd(ans1[q[i].id],ans2[q[i].id]);
		ans1[q[i].id]/=g;
		ans2[q[i].id]/=g;
	}
	for(int i=1;i<=m;i++)
		cout<<ans1[i]<<"/"<<ans2[i]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}