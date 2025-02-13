/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:49:14
 * @LastEditTime: 2024-01-17 14:49:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int a[N],b[N];
void solve()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	int m=0;
	int ans=0;
	for(int i=1;i<=min(n,k);i++)
	{
		if(m<b[i]) m=b[i];
		ans=max(ans,a[i]+(k-i)*m);
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