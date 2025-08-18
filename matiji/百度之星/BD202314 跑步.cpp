/*
 * @Author: dsaDadas11
 * @Date: 2024-05-27 22:50:57
 * @LastEditTime: 2024-05-27 22:51:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,ans=1,cnt=1;
struct pp
{
	int p,v;
	bool operator<(const pp&a) const
	{
		if(p==a.p) return v<a.v;
		return p<a.p;
	}
}b[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].p>>b[i].v;
	}
	sort(b+1,b+1+n);
	for(int i=1;i<n;i++)
	{
		if(b[i].p==b[i+1].p)
		{
			b[i+1].v=b[i].v;
		}
	}
	for(int i=n;i>=2;i--)
	{
		if(b[i].v<b[i-1].v||b[i].p==b[i-1].p)
		{
			cnt++;
			b[i-1].v=b[i].v;
		}
		else cnt=1;
		ans=max(ans,cnt);
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