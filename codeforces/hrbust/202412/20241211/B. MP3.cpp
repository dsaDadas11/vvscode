/*
* @Author: dsaDadas11
* @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-12-11 22:02:23
* @Description: go for it!
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n, m;
int a[N],b[N],pre[N];
int count(int l,int r)
{
	return pre[r]-pre[l-1];
}
bool check(int l,int r)
{
	int k=r-l+1;
	k=ceil(log2(k));
	if(k*n>m) return 0;
	return 1;
}
void solve()
{
	cin>>n>>m;
	m*=8;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int len=unique(b+1,b+1+n)-(b+1);
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+len,a[i])-b;
	for (int i=1;i<=n;i++)
	{
		pre[a[i]]++;
	}
	for (int i=1;i<=n;i++)
	{
		pre[i]+=pre[i-1];
	}
	int ans=1e18;
	for (int i=1;i<=len;i++)
	{
		int l=i,r=len;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if (check(i,mid)) l=mid;
			else r=mid-1;  
		}
		if(check(i,l))
		{
			ans=min(ans,n-count(i,l));
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 自己写的
 一开始卡n*logn*logn
 然后发现离散化之后可以不用在check里面再加lower_bound，直接用r-l+1即可

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N],b[N],c[N];
int len;
bool check(int l,int r)
{
	int k=r-l+1;
	k=ceil(log2(k));
	if(k*n>m) return 1;
	return 0;
}
void solve()
{
	cin>>n>>m;
	m*=8;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=c[i]=a[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	len=unique(a+1,a+1+n)-(a+1);
	unique(c+1,c+1+n);
	for(int i=1;i<=len;i++)
	{
		a[i]=lower_bound(c+1,c+1+len,a[i])-c;
	}
	int ans=1e9;
	for(int i=1;i<=len;i++)
	{
		int l=i,r=len;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(check(a[i],mid)) r=mid-1;
			else l=mid;
		}
		
		int p1=lower_bound(b+1,b+1+n,c[i])-b;
		p1--;
		int p2=upper_bound(b+1,b+1+n,c[l])-b;
		
		ans=min(ans,p1-1+1+n-p2+1);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

*/