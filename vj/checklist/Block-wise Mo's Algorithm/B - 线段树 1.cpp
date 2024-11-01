/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-16 20:09:00
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,m,len,a[N],ed[N],st[N],add[N],sum[N],id[N];
void change(int l,int r,int k)
{
	if(id[l]==id[r])
	{
		for(int i=l;i<=r;i++) a[i]+=k,sum[id[i]]+=k;
	}
	else
	{
		for(int i=l;i<=ed[l];i++) a[i]+=k,sum[id[i]]+=k;
		for(int i=st[r];i<=r;i++) a[i]+=k,sum[id[i]]+=k;
		for(int i=ed[l]+1;i<st[r];i+=len) add[id[i]]+=k;
	}
}
int query(int l,int r)
{
	int ans=0;
	if(id[l]==id[r])
	{
		for(int i=l;i<=r;i++) ans+=a[i]+add[id[i]];
	}
	else
	{
		for(int i=l;i<=ed[l];i++) ans+=a[i]+add[id[i]];
		for(int i=st[r];i<=r;i++) ans+=a[i]+add[id[i]];
		for(int i=ed[l]+1;i<st[r];i+=len) ans+=sum[id[i]]+add[id[i]]*(ed[i]-st[i]+1);
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		id[i]=(i-1)/len+1;
		st[i]=(id[i]-1)*len+1;
		ed[i]=min(id[i]*len,n);
		sum[id[i]]+=a[i];
	}
	while(m--)
	{
		int op,x,y; cin>>op>>x>>y;
		if(op==1)
		{
			int k; cin>>k;
			change(x,y,k);
		}
		else
		{
			cout<<query(x,y)<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}