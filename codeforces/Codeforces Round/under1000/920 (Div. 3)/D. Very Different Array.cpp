/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:59:25
 * @LastEditTime: 2024-01-17 14:59:32
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int a[N],b[N],pre_a[N],pre_b[N];
bool cmp(int x,int y){return x>y;}
void solve()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++)
	{
		pre_a[i]=pre_a[i-1]+a[i];
	}
	for(int i=1;i<=m;i++)
	{
		pre_b[i]=pre_b[i-1]+b[i];
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int tot=(pre_a[i]-pre_b[i])+(pre_b[m]-pre_b[m-n+i])-(pre_a[n]-pre_a[i]);
		ans=max(ans,tot);
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