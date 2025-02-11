/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2025-01-11 19:03:17
 * @Description: go for it!
 */
// URL: https://loj.ac/p/130
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int tr[N],a[N];
int n,q;
int lowbit(int x){return x&(-x);}
void add(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
int sum(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i)) ans+=tr[i];
	return ans;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add(i,a[i]);
	}
	while(q--)
	{
		int op; cin>>op;
		if(op==1)
		{
			int i,x; cin>>i>>x;
			add(i,x);
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