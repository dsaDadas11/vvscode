/*
 * @Author: dsaDadas11
 * @Date: 2024-02-01 19:46:57
 * @LastEditTime: 2024-02-01 19:47:02
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q;
int a[N],b[N],tr1[N],tr2[N];
int lowbit(int x){return x&(-x);}
void add(int p,int x)
{
	for(int i=p;i<=n;i+=lowbit(i))
	{
		tr1[i]+=x;
		tr2[i]+=x*p;
	}
}
int sum(int p)
{
	int ans=0;
	for(int i=p;i;i-=lowbit(i))
	{
		ans+=(p+1)*tr1[i]-tr2[i];
	}
	return ans;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		add(i,b[i]);
	}
	while(q--)
	{
		int op; cin>>op;
		if(op==1)
		{
			int l,r,x; cin>>l>>r>>x;
			add(l,x),add(r+1,-x);
		}
		else
		{
			int l,r; cin>>l>>r;
			cout<<sum(r)-sum(l-1)<<endl;
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