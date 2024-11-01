/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-17 14:46:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,m,len,st[N],ed[N],id[N],tar[N],a[N],b[N];
void change(int x,int k)
{
	a[x]=k;
	for(int i=x;i>=st[x];i--)
	{
		if(i+a[i]>ed[x])
		{
			tar[i]=i+a[i];
			b[i]=1;
		}
		else
		{
			tar[i]=tar[i+a[i]];
			b[i]=b[i+a[i]]+1;
		}
	}
}
int query(int x)
{
	int ans=0;
	while(x<=n)
	{
		ans+=b[x];
		x=tar[x];
	}
	return ans;
}
void solve()
{
	cin>>n;
	len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		id[i]=(i-1)/len+1;
		st[i]=(id[i]-1)*len+1;
		ed[i]=min(id[i]*len,n);
	}
	for(int i=st[1];i<=ed[n];i+=len)
	{
		for(int j=ed[i];j>=st[i];j--)
		{
			if(j+a[j]>ed[i])
			{
				tar[j]=j+a[j];
				b[j]=1;
			}
			else
			{
				tar[j]=tar[j+a[j]];
				b[j]=b[j+a[j]]+1;
			}
		}
	}
	cin>>m;
	while(m--)
	{
		int op,x; cin>>op>>x;
		if(op==1)
		{
			cout<<query(x+1)<<endl;
		}
		else
		{
			int k; cin>>k;
			change(x+1,k);
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