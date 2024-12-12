/*
 * @Author: dsaDadas11
 * @Date: 2024-11-24 19:56:31
 * @LastEditTime: 2024-11-24 19:56:45
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int len;
int mq,mr;
struct op
{
	int l,r;
	int idx,tim;
	bool operator<(const op& that) const
	{
		if(l/len!=that.l/len) return l<that.l;
		if(r/len!=that.r/len) return r<that.r;
		return tim<that.tim;
	}
}q[N];
struct modify
{
	int p,c;
}R[N];
int a[N],cnt[N];
int ans[N];
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
	cin>>n>>m;
	len=pow(n,2.0/3.0);
	int l,r;
	char ch;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>ch>>l>>r;
		if(ch=='Q') q[++mq]={l,r,mq,mr};
		else R[++mr]={l,r};
	}
	sort(q+1,q+1+mq);
	for(int i=1,l=1,r=0,x=0;i<=mq;i++)
	{
		while(q[i].l<l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(q[i].r<r) del(a[r--]);

		// 时间戳
		// 要将 a[pos] 和 R[x].c 交换，而不能用其他变量代替，因为需要来回滚动
		while(x<q[i].tim)
		{
			++x; // 先加
			int pos=R[x].p;
			// 修改数在区间内
			if(l<=pos&&pos<=r)
			{
				add(R[x].c);
				del(a[pos]);
			}
			swap(a[pos],R[x].c);
		}
		while(x>q[i].tim)
		{
			int pos=R[x].p;
			if(l<=pos&&pos<=r)
			{
				add(R[x].c);
				del(a[pos]);
			}
			swap(a[pos],R[x].c);
			x--; // 后减
		}
		ans[q[i].idx]=res;
	}

	for(int i=1;i<=mq;i++)
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