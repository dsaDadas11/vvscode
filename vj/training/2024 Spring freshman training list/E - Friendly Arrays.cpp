/*
 * @Author: dsaDadas11
 * @Date: 2024-04-16 19:41:30
 * @LastEditTime: 2024-04-16 19:41:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],b[N];
void solve()
{
	int n,m;
	cin>>n>>m;
	int s=0;
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		s|=b[i];
	}
	for(int i=1;i<=n;i++) ans1^=a[i];
	for(int i=1;i<=n;i++)
	{
		a[i]|=s;
		ans2^=a[i];
	}
	if(n%2) cout<<ans1<<' '<<ans2<<endl;
	else cout<<ans2<<' '<<ans1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}