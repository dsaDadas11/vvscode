/*
 * @Author: dsaDadas11
 * @Date: 2024-08-19 18:13:18
 * @LastEditTime: 2024-08-19 18:13:25
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
int a[N],b[N];
void solve()
{
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i]-1;
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	sum=min(sum,m-1);
	if(sum<=k-1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}