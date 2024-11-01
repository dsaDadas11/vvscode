/*
 * @Author: dsaDadas11
 * @Date: 2024-02-04 11:29:24
 * @LastEditTime: 2024-02-04 11:29:29
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int t[N],pre[N];
void solve()
{
	int n,q,tc; cin>>n>>q>>tc;
	for(int i=1;i<=n;i++) cin>>t[i];
	sort(t+1,t+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+t[i];
	while(q--)
	{
		int m; cin>>m;
		int p=m/tc;
		if(p>n) cout<<tc<<endl;
		else cout<<pre[n-p]+tc<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}