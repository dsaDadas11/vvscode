/*
 * @Author: dsaDadas11
 * @Date: 2024-02-17 10:18:18
 * @LastEditTime: 2024-02-17 10:18:27
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int a[N],b[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	b[n]=n;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]==a[i+1]) b[i]=b[i+1];
		else b[i]=i;
	}
	int q; cin>>q;
	while(q--)
	{
		int l,r; cin>>l>>r;
		if(b[l]<r) cout<<l<<' '<<b[l]+1<<endl;
		else cout<<"-1 -1"<<endl;
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}