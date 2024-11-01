/*
 * @Author: dsaDadas11
 * @Date: 2024-02-01 18:38:22
 * @LastEditTime: 2024-02-01 18:38:29
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
int a[N],tr[N];
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
		add(i,a[i]-a[i-1]);
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
			int i; cin>>i;
			cout<<sum(i)<<endl;
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