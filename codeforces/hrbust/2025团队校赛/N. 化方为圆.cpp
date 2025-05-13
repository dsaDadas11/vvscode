/*
 * @Author: dsaDadas11
 * @Date: 2025-04-13 19:37:53
 * @LastEditTime: 2025-04-13 19:38:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=10000;
int n,c,d;
int a[N];
void prn(int x)
{
	string s=to_string(x);
	while(s.size()<4)
	{
		s.insert(s.begin(),'0');
	}
	cout<<s<<endl;
}
void solve()
{
	cin>>n>>c>>d;
	c%=mod,d%=mod;
	a[1]=1;
	for(int i=2;i<=10000;i++)
	{
		a[i]=c*a[i-1]*a[i-1]%mod+d;
		a[i]%=mod;
	}
	vector<int> cnt(10007);
	int mx=0;
	for(int i=1;i<=10000;i++)
	{
		a[i]%=mod;
		cnt[a[i]]++;
		mx=max(mx,cnt[a[i]]);
	}
	vector<int> st;
	for(int i=1;i<=10000;i++)
	{
		if(cnt[a[i]]>1) break;
		st.push_back(a[i]);
	}
	vector<int> roun;
	vector<int> vis(10007);
	for(int i=1;i<=10000;i++)
	{
		if(cnt[i]>1)
		{
			vis[i]=1;
		}
	}
	for(int i=1;i<=10000;i++)
	{
		if(vis[a[i]])
		{
			roun.push_back(a[i]);
			vis[a[i]]=0;
		}
	}
	if(n<=(int)st.size()) return prn(st[n-1]),void();
	n-=st.size();
	n%=roun.size();
	if(n==0) prn(roun.back());
	else prn(roun[n-1]);
	
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}