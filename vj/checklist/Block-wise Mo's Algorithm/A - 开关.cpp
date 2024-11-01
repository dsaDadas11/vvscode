/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-16 20:08:26
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,m,len,a[N],st[N],ed[N],id[N],sum[N],add[N];
void change(int l,int r,int k)
{
	if(id[l]==id[r])
	{
		for(int i=l;i<=r;i++) a[i]+=k,sum[id[i]]+=(((a[i]+add[id[i]])%2)?1:-1);
	}
	else
	{
		for(int i=l;i<=ed[l];i++) a[i]+=k,sum[id[i]]+=(((a[i]+add[id[i]])%2)?1:-1);
		for(int i=st[r];i<=r;i++) a[i]+=k,sum[id[i]]+=(((a[i]+add[id[i]])%2)?1:-1);
		for(int i=ed[l]+1;i<st[r];i+=len) add[id[i]]+=k,sum[id[i]]=len-sum[id[i]];
	}
}
int query(int l,int r)
{
	int ans=0;
	if(id[l]==id[r])
	{
		for(int i=l;i<=r;i++) ans+=((a[i]+add[id[i]])%2?1:0);
	}
	else
	{
		for(int i=l;i<=ed[l];i++) ans+=((a[i]+add[id[i]])%2?1:0);
		for(int i=st[r];i<=r;i++) ans+=((a[i]+add[id[i]])%2?1:0);
		for(int i=ed[l]+1;i<st[r];i+=len) ans+=sum[id[i]];
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		id[i]=(i-1)/len+1;
		st[i]=(id[i]-1)*len+1;
		ed[i]=id[i]*len;
	}
	while(m--)
	{
		int op,l,r; cin>>op>>l>>r;
		if(op==0)
		{
			change(l,r,1);
		}
		else
		{
			cout<<query(l,r)<<endl;
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