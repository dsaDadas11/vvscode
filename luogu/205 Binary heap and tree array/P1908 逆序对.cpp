/*
 * @Author: dsaDadas11
 * @Date: 2024-02-02 11:06:32
 * @LastEditTime: 2024-02-02 11:06:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],b[N],tr[N];
int n;
int lowbit(int x){return x&(-x);}
void add(int p,int x)
{
	for(int i=p;i<=n;i+=lowbit(i)) tr[i]+=x;
}
int query(int p)
{
	int ans=0;
	for(int i=p;i;i-=lowbit(i)) ans+=tr[i];
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+n,a[i])-b;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=i-1-query(a[i]);
		add(a[i],1);
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