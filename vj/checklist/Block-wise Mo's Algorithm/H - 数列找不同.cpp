/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-19 20:19:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,m,len,que;
int a[N],cnt[N];
bool ans[N];
struct op
{
	int l,r,id;
	bool operator<(const op&that)const
	{
		if((l-1)/len!=(that.l-1)/len) return l<that.l;
		return r<that.r;
	}
}q[N];
void add(int x)
{
	if(++cnt[x]==1) que++;
}
void del(int x)
{
	if(--cnt[x]==0) que--;
}
void solve()
{
	cin>>n>>m;
	len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		q[i].id=i;
		cin>>q[i].l>>q[i].r;
	}
	sort(q+1,q+1+m);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		while(l<q[i].l) del(a[l++]);
		while(l>q[i].l) add(a[--l]);
		while(r>q[i].r) del(a[r--]);
		while(r<q[i].r) add(a[++r]);
		if(que==q[i].r-q[i].l+1) ans[q[i].id]=1;
		else ans[q[i].id]=0;
	}
	for(int i=1;i<=m;i++) cout<<(ans[i]?"Yes":"No")<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}