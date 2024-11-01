/*
 * @Author: dsaDadas11
 * @Date: 2024-03-28 16:33:17
 * @LastEditTime: 2024-03-28 16:33:26
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=1;i<n;i++)
	{
		if((i>a[i]&&i<a[i+1]))
		{
			ans++;
		}
	}
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) f=0;
	}
	if(f) ans++;
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}