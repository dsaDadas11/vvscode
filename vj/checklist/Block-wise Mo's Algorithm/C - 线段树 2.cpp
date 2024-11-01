/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 09:01:26
 * @LastEditTime: 2024-01-17 15:34:38
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,m,q,len,a[N],ed[N],st[N],add[N],sum[N],id[N],mul[N];
// sum[N]维护所有块的性质，add[N]维护整块的性质（不包括零散块）
void reset(int x)
{
	for(int i=st[x];i<=ed[x];i++)
	{
		a[i]=(a[i]*mul[id[x]]+add[id[x]])%m;
	}
	mul[id[x]]=1,add[id[x]]=0;
}
void multiple(int l,int r,int k)
{
	if(id[l]==id[r])
	{
		reset(l);
		for(int i=l;i<=r;i++) sum[id[i]]=(sum[id[i]]+(k-1)*a[i])%m,a[i]=(a[i]*k)%m;
	}
	else
	{
		reset(l),reset(r);
		for(int i=l;i<=ed[l];i++) sum[id[i]]=(sum[id[i]]+(k-1)*a[i])%m,a[i]=(a[i]*k)%m;
		for(int i=st[r];i<=r;i++) sum[id[i]]=(sum[id[i]]+(k-1)*a[i])%m,a[i]=(a[i]*k)%m;
		for(int i=ed[l]+1;i<st[r];i+=len)
		{
			sum[id[i]]=(sum[id[i]]*k)%m;
			mul[id[i]]=(mul[id[i]]*k)%m;
			add[id[i]]=(add[id[i]]*k)%m;
		}
	}
}
void addition(int l,int r,int k)
{
	if(id[l]==id[r])
	{
		reset(l);
		for(int i=l;i<=r;i++) a[i]=(a[i]+k)%m;
		sum[id[l]]=(sum[id[l]]+k*(r-l+1))%m;
	}
	else
	{
		reset(l),reset(r);
		for(int i=l;i<=ed[l];i++) a[i]=(a[i]+k)%m;
		sum[id[l]]=(sum[id[l]]+k*(ed[l]-l+1))%m;
		for(int i=st[r];i<=r;i++) a[i]=(a[i]+k)%m;
		sum[id[r]]=(sum[id[r]]+k*(r-st[r]+1))%m;
		for(int i=ed[l]+1;i<st[r];i+=len) add[id[i]]=(add[id[i]]+k)%m,sum[id[i]]=(sum[id[i]]+k*len)%m;
	}
}
int query(int l,int r)
{
	int ans=0;
	if(id[l]==id[r])
	{
		for(int i=l;i<=r;i++) ans=(ans+a[i]*mul[id[i]]+add[id[i]])%m;
	}
	else
	{
		for(int i=l;i<=ed[l];i++) ans=(ans+a[i]*mul[id[i]]+add[id[i]])%m;
		for(int i=st[r];i<=r;i++) ans=(ans+a[i]*mul[id[i]]+add[id[i]])%m;
		for(int i=ed[l]+1;i<st[r];i+=len) ans=(ans+sum[id[i]])%m;
	}
	return ans;
}
void solve()
{
	cin>>n>>q>>m;
	len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		mul[i]=1;
		cin>>a[i];
		id[i]=(i-1)/len+1;
		st[i]=(id[i]-1)*len+1;
		ed[i]=min(id[i]*len,n);
		sum[id[i]]+=a[i];
	}
	while(q--)
	{
		int op,x,y; cin>>op>>x>>y;
		if(op==1)
		{
			int k; cin>>k;
			multiple(x,y,k);
		}
		else if(op==2)
		{
			int k; cin>>k;
			addition(x,y,k);
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