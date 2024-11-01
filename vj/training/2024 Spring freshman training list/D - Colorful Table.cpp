/*
 * @Author: dsaDadas11
 * @Date: 2024-04-16 20:35:57
 * @LastEditTime: 2024-04-16 20:36:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int a[N],s[N],e[N];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=k;i++)
	{
		s[i]=n+1;
		e[i]=0;
	}
	int m=0;
	for(int i=1;i<=n;i++)
	{
		m=max(m,a[i]);
		s[a[i]]=min(s[a[i]],i);
		e[a[i]]=max(e[a[i]],i);
	}
	int pre=m;
	for(int i=m-1;i>=1;i--)
	{
		if(s[i]==n+1) continue;
		s[i]=min(s[pre],s[i]);
		e[i]=max(e[pre],e[i]);
		pre=i;
	}
	for(int i=1;i<=k;i++)
	{
		if(s[i]==n+1) cout<<"0 ";
		else cout<<2*(e[i]-s[i]+1)<<' ';
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