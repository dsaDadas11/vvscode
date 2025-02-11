/*
 * @Author: dsaDadas11
 * @Date: 2025-01-14 18:14:49
 * @LastEditTime: 2025-01-14 18:15:04
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
struct op
{
	int x,y,z;
};
int ans[N];
void solve()
{
	cin>>n;
	for(int i=0;i<=n+5;i++) ans[i]=0;
	int x,y,z;
	map<int,int> mpx,mpy,mpz;
	vector<op> v(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		v[i]={x,y,z};
		mpx[x]++,mpy[y]++,mpz[z]++;
	}
	for(int i=1;i<=n;i++)
	{
		auto [x,y,z]=v[i];
		ans[i]=max({mpx[x],mpy[y],mpz[z]})-1;
	}
	map<int,int> cnt;
	for(int i=1;i<=n;i++)
	{
		cnt[ans[i]]++;
	}
	int res=0;
	cout<<"0 ";
	for(int i=1;i<n;i++)
	{
		res+=cnt[i-1];
		cout<<res<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}