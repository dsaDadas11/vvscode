/*
 * @Author: dsaDadas11
 * @Date: 2024-10-13 15:05:05
 * @LastEditTime: 2024-10-13 15:05:11
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
	int mn=1e18;
	for(int i=1;i<n;i++)
	{
		mn=min(mn,max(a[i],a[i+1]));
	}
	cout<<mn-1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}