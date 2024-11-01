/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-01-16 20:09:33
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
//#define ll long long
//#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,m,len,a[N],st[N],ed[N],mx[N],id[N];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int query(int l,int r)
{
	int ans=0;
	if(id[l]==id[r])
	{
		for(int i=l;i<=r;i++) ans=max(ans,a[i]);
	}
	else
	{
		for(int i=l;i<=ed[l];i++) ans=max(ans,a[i]);
		for(int i=st[r];i<=r;i++) ans=max(ans,a[i]);
		for(int i=ed[l]+1;i<st[r];i+=len) ans=max(ans,mx[id[i]]);
	}
	return ans;
}
void solve()
{
	n=read();
	m=read();
	len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		id[i]=(i-1)/len+1;
		st[i]=(id[i]-1)*len+1;
		ed[i]=min(n,id[i]*len);
		mx[id[i]]=max(mx[id[i]],a[i]);
	}
	while(m--)
	{
		int l,r;
		l=read();
		r=read();
		cout<<query(l,r)<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}