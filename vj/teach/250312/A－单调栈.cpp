/*
 * @Author: dsaDadas11
 * @Date: 2025-03-16 21:10:12
 * @LastEditTime: 2025-03-16 21:10:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
int stk[N];
int ans[N];
int p;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		while(p&&a[i]>a[stk[p]])
		{
			ans[stk[p]]=i;
			p--;
		}
		stk[++p]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}