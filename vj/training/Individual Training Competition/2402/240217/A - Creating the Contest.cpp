/*
 * @Author: dsaDadas11
 * @Date: 2024-02-17 19:45:21
 * @LastEditTime: 2024-02-17 19:45:27
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
	int ans=1;
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(a[i+1]<=2*a[i]) cnt++;
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