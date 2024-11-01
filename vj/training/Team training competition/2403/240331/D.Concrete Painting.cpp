/*
 * @Author: dsaDadas11
 * @Date: 2024-04-01 21:26:10
 * @LastEditTime: 2024-04-01 21:26:14
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int p[N];
void solve()
{
	int n;
	cin>>n;
	vector<int> l(n),r(n),v;
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>r[i];
		v.push_back(l[i]);
		v.push_back(r[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int m=v.size();
	vector<int> cnt(m);
	for(int i=0;i<n;i++)
	{
		cnt[lower_bound(v.begin(),v.end(),l[i])-v.begin()]++;
		cnt[lower_bound(v.begin(),v.end(),r[i])-v.begin()]--;
	}
	p[0]=1;
	for(int i=1;i<N;i++)
	{
		p[i]=(p[i-1]*2)%mod;
	}
	int ans=0;
	partial_sum(cnt.begin(),cnt.end(),cnt.begin());
	for(int i=1;i<m;i++)
	{
		int temp=(v[i]-v[i-1])%mod*(p[cnt[i-1]]-1)%mod*(p[n-cnt[i-1]])%mod;
		ans=(ans+temp)%mod;
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