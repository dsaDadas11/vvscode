/*
 * @Author: dsaDadas11
 * @Date: 2024-11-10 12:56:21
 * @LastEditTime: 2024-11-10 12:56:28
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
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int sum=0;
	int maxn=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		maxn=max(maxn,a[i]);
		if(maxn*2==sum) ans++;
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