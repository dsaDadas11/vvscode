/*
 * @Author: dsaDadas11
 * @Date: 2024-02-03 21:44:00
 * @LastEditTime: 2024-02-03 21:44:10
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
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(k==0)
	{
		if(a[1]-1<1) cout<<"-1"<<endl;
		else cout<<a[1]-1<<endl;
		return;
	}
	if(a[k]==a[k+1]) cout<<"-1"<<endl;
	else cout<<a[k]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}