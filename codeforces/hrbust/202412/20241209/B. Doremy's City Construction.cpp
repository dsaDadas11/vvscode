/*
 * @Author: dsaDadas11
 * @Date: 2024-12-09 18:51:50
 * @LastEditTime: 2024-12-09 18:52:02
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
int a[N];
int pos[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pos[a[i]]=-1;
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		if(pos[a[i]]==-1) pos[a[i]]=i;
	}
	int ans=n/2;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		if(pos[a[j]]>=1&&pos[a[j]]<=n) j=pos[a[j]];
		ans=max(ans,j*(n-j));
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}