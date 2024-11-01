/*
 * @Author: dsaDadas11
 * @Date: 2024-03-26 21:24:38
 * @LastEditTime: 2024-03-26 21:26:14
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
	int sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		double ave=1.0*sum/i;
		int x=upper_bound(a+1,a+1+i,ave)-a;
		ans=max(ans,i-x+1);
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