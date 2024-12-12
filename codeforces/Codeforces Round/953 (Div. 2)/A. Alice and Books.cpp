/*
 * @Author: dsaDadas11
 * @Date: 2024-11-22 22:42:11
 * @LastEditTime: 2024-11-22 22:42:17
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
int a[107];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maxn=0;
	for(int i=1;i<n;i++)
	{
		maxn=max(maxn,a[i]);
	}
	cout<<maxn+a[n]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}